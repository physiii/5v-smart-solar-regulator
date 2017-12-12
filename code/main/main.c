/*
 * Example ESP32 app code using Libwebsockets
 *
 * Copyright (C) 2017 Andy Green <andy@warmcat.com>
 *
 * This file is made available under the Creative Commons CC0 1.0
 * Universal Public Domain Dedication.
 *
 * The person who associated a work with this deed has dedicated
 * the work to the public domain by waiving all of his or her rights
 * to the work worldwide under copyright law, including all related
 * and neighboring rights, to the extent allowed by law. You can copy,
 * modify, distribute and perform the work, even for commercial purposes,
 * all without asking permission.
 *
 * The test apps are intended to be adapted for use in your code, which
 * may be proprietary.	So unlike the library itself, they are licensed
 * Public Domain.
 *
 */
#include <libwebsockets.h>
#include <nvs_flash.h>

/*
 * Configuration for normal station website
 *
 * We implement the generic lws test server features using
 * generic plugin code from lws.  Normally these plugins
 * are dynamically loaded at runtime, but we use them by
 * statically including them.
 *
 * To customize for your own device, you would remove these
 * and put your own plugin include here
 */

#include "../components/libwebsockets/plugins/protocol_lws_mirror.c"
#include "../components/libwebsockets/plugins/protocol_post_demo.c"
#include "../components/libwebsockets/plugins/protocol_lws_status.c"
#include "../components/libwebsockets/plugins/protocol_lws_meta.c"
#include <protocol_esp32_lws_reboot_to_factory.c>

#include "plugins/protocol_token.c"
#include "plugins/protocol_climate.c"
#include "plugins/protocol_power.c"

static const struct lws_protocols protocols_station[] = {
	{
		"http-only",
		lws_callback_http_dummy,
		0,
		1024, 0, NULL, 900
	},
	LWS_PLUGIN_PROTOCOL_TOKEN, /* demo... */
	LWS_PLUGIN_PROTOCOL_CLIMATE, /* demo... */
	LWS_PLUGIN_PROTOCOL_POWER, /* demo... */
	LWS_PLUGIN_PROTOCOL_MIRROR,	    /* replace with */
	LWS_PLUGIN_PROTOCOL_POST_DEMO,	    /* your own */
	LWS_PLUGIN_PROTOCOL_LWS_STATUS,	    /* plugin protocol */
	LWS_PLUGIN_PROTOCOL_ESPLWS_RTF,	/* helper protocol to allow reset to factory */
	LWS_PLUGIN_PROTOCOL_LWS_META,	    /* protocol multiplexer */
	{ NULL, NULL, 0, 0, 0, NULL, 0 } /* terminator */
};

static const struct lws_protocol_vhost_options pvo_headers = {
        NULL,
        NULL,
        "Keep-Alive:",
        "timeout=5, max=20",
};

/* reset to factory mount */
static const struct lws_http_mount mount_station_rtf = {
	.mountpoint		= "/esp32-rtf",
	.origin			= "esplws-rtf",
	.origin_protocol	= LWSMPRO_CALLBACK,
	.mountpoint_len		= 10,
};

/*
 * this makes a special URL "/formtest" which gets passed to
 * the "protocol-post-demo" plugin protocol for handling
 */
static const struct lws_http_mount mount_station_post = {
	.mount_next		= &mount_station_rtf,
	.mountpoint		= "/formtest",
	.origin			= "protocol-post-demo",
	.origin_protocol	= LWSMPRO_CALLBACK,
	.mountpoint_len		= 9,
};

/*
 * this serves "/station/..." in the romfs at "/" in the URL namespace
 */
static const struct lws_http_mount mount_station = {
        .mount_next		= &mount_station_post,
        .mountpoint		= "/",
        .origin			= "/station",
        .def			= "test.html",
        .origin_protocol	= LWSMPRO_FILE,
        .mountpoint_len		= 1,
};

bool got_ip = false;
esp_err_t event_handler(void *ctx, system_event_t *event)
{
	/* deal with your own user events here first */

    switch(event->event_id) {
        case SYSTEM_EVENT_STA_START:
            printf("SYSTEM_EVENT_STA_START\n");
    //do not actually connect in test case
            //;
            break;
        case SYSTEM_EVENT_STA_GOT_IP:
            printf("got ip: %s\n",
            ip4addr_ntoa(&event->event_info.got_ip.ip_info.ip));
	    got_ip = true;
            break;
        case SYSTEM_EVENT_STA_DISCONNECTED:
            printf("SYSTEM_EVENT_STA_DISCONNECTED\n");
	    /*token_connect = true;
	    token_received = false;
	    climate_connect = true;
	    climate_linked = false;
	    power_connect = true;
	    power_linked = false;*/
	    got_ip = false;
            //TEST_ESP_OK(esp_wifi_connect());
            break;
        default:
 	    printf("ev_handle_called.\n");
            break;
    }
    //return ESP_OK;

	return lws_esp32_event_passthru(ctx, event);
}

/*
 * This is called when the user asks to "Identify physical device"
 * he is configuring, by pressing the Identify button on the AP
 * setup page for the device.
 *
 * It should do something device-specific that
 * makes it easy to identify which physical device is being
 * addressed, like flash an LED on the device on a timer for a
 * few seconds.
 */
void
lws_esp32_identify_physical_device(void)
{
	lwsl_notice("%s\n", __func__);
}

void lws_esp32_leds_timer_cb(TimerHandle_t th)
{
}

void app_main(void)
{
	char tag[50] = "[connection-loop]";
	static struct lws_context_creation_info info;
	struct lws_context *context;
	struct lws_vhost *vh;

	lws_esp32_set_creation_defaults(&info);

	info.port = 443;
	info.fd_limit_per_thread = 10;
	info.max_http_header_pool = 12;
	info.max_http_header_data = 512;
	info.pt_serv_buf_size = 900;
	info.keepalive_timeout = 5;
	info.simultaneous_ssl_restriction = 4;
	info.options = LWS_SERVER_OPTION_EXPLICIT_VHOSTS |
		       LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;

	info.ssl_cert_filepath = "ap-cert.pem";
	info.ssl_private_key_filepath = "ap-key.pem";

	info.vhost_name = "station";
	info.protocols = protocols_station;
	info.mounts = &mount_station;
	info.headers = &pvo_headers;

	nvs_flash_init();
	lws_esp32_wlan_config();

	ESP_ERROR_CHECK( esp_event_loop_init(event_handler, NULL));

	lws_esp32_wlan_start_station();
	context = lws_esp32_init(&info, &vh);

 	print_mux = xSemaphoreCreateMutex();
        i2c_example_slave_init();
        i2c_example_master_init();

	gpio_init();
        xTaskCreate(climate_task, "climate_task_0", 1024 * 2, (void* ) 0, 10, NULL);
	xTaskCreate(power_task, "power_task", 1024 * 2, (void* ) 0, 10, NULL);

	static struct lws_client_connect_info i;
	memset(&i, 0, sizeof i);
	i.address = "192.168.0.10";
        i.port = 4000;
	i.ssl_connection = 0;
	i.host = i.address;
	i.origin = i.host;
        i.ietf_version_or_minus_one = -1;
	i.context = context;

	while (!got_ip) {
    		vTaskDelay(100 / portTICK_RATE_MS);
	}

	struct lws *wsi;
	while (!lws_service(context, 3000)) {
		taskYIELD();
		if (!got_ip) continue;
	
		if (token_connect) {
	    		//vTaskDelay(5000 / portTICK_RATE_MS);
			printf("%s token protocol\n",tag);
			//token_connect = false;
			//wsi = NULL;
			i.pwsi = &wsi;
			i.protocol = "token-protocol";
			i.path = "/tokens";
        		wsi = lws_client_connect_via_info(&i);
		}

		if (climate_connect) {
			printf("%s climate protocol\n",tag);
			//climate_connect = false;
			//wsi = NULL;
			i.pwsi = &wsi;
			i.protocol = "climate-protocol";
			i.path = "/climate";
   			wsi = lws_client_connect_via_info(&i);
		}

		if (power_connect) {
			printf("%s power protocol\n",tag);
			//power_connect = false;
			//wsi = NULL;
			i.pwsi = &wsi;
			i.protocol = "power-protocol";
			i.path = "/power";
	        	wsi = lws_client_connect_via_info(&i);
		}

 		//vTaskDelay(1000 / portTICK_RATE_MS);
  		//printf("[lws_service loop]\n");
	}
}
