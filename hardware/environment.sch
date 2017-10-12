EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:open-automation
LIBS:smart-regulator-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 4800 1300 0    197  ~ 0
Environment
Text GLabel 3050 3200 0    60   Input ~ 0
VCC_I2C
$Comp
L GND #PWR028
U 1 1 59C50BD3
P 3500 3350
F 0 "#PWR028" H 3500 3100 50  0001 C CNN
F 1 "GND" H 3500 3200 50  0000 C CNN
F 2 "" H 3500 3350 50  0000 C CNN
F 3 "" H 3500 3350 50  0000 C CNN
	1    3500 3350
	1    0    0    -1  
$EndComp
Text GLabel 4500 3200 2    60   Input ~ 0
SCL
Text GLabel 4500 3300 2    60   Input ~ 0
SDA
$Comp
L SI7020-A20 U6
U 1 1 59C50BD4
P 4000 3300
F 0 "U6" H 4200 3200 60  0000 C CNN
F 1 "SI7020-A20" H 4000 3500 60  0000 C CNN
F 2 "open-automation:SI7020-A20" H 4000 3000 60  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/silicon-labs/SI7020-A20-GM1R/336-3596-1-ND/5823452" H 4000 3100 60  0001 C CNN
F 4 "SI7020-A20-GM1R" H 4100 3100 60  0001 C CNN "Part Number"
	1    4000 3300
	1    0    0    -1  
$EndComp
$Comp
L C_0.1uF C9
U 1 1 59C50BD5
P 3200 3400
F 0 "C9" H 3225 3500 50  0000 L CNN
F 1 "C_0.1uF" H 2900 3300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3300 3700 50  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/kemet/C0603C104K5RACTU/399-5089-1-ND/1465623" H 3200 3150 50  0001 C CNN
F 4 "C0603C104K5RACTU" H 3325 3600 60  0001 C CNN "Part Number"
	1    3200 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 59C50BD6
P 3200 3600
F 0 "#PWR029" H 3200 3350 50  0001 C CNN
F 1 "GND" H 3200 3450 50  0000 C CNN
F 2 "" H 3200 3600 50  0000 C CNN
F 3 "" H 3200 3600 50  0000 C CNN
	1    3200 3600
	1    0    0    -1  
$EndComp
Text Label 7150 2700 0    60   ~ 0
Light-Level
$Comp
L OPT3001 U7
U 1 1 59C50BD7
P 7500 3200
F 0 "U7" H 7650 2950 60  0000 C CNN
F 1 "OPT3001" H 7500 3350 60  0000 C CNN
F 2 "Housings_DFN_QFN:DFN-6-1EP_2x2mm_Pitch0.65mm" H 7550 2850 60  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/texas-instruments/OPT3001DNPR/296-40474-1-ND/5178351" H 7650 2950 60  0001 C CNN
F 4 "296-40474-1-ND" H 7750 3050 60  0001 C CNN "Part Number"
	1    7500 3200
	1    0    0    -1  
$EndComp
Text GLabel 7900 3100 1    60   Input ~ 0
SDA
Text GLabel 7900 3400 3    60   Input ~ 0
SCL
$Comp
L GND #PWR030
U 1 1 59C50BD8
P 7150 3400
F 0 "#PWR030" H 7150 3150 50  0001 C CNN
F 1 "GND" H 7150 3250 50  0000 C CNN
F 2 "" H 7150 3400 50  0000 C CNN
F 3 "" H 7150 3400 50  0000 C CNN
	1    7150 3400
	1    0    0    -1  
$EndComp
Text GLabel 6700 3150 0    60   Input ~ 0
VCC_I2C
$Comp
L C_0.1uF C10
U 1 1 59C50BDA
P 6850 3350
F 0 "C10" H 6875 3450 50  0000 L CNN
F 1 "C_0.1uF" H 6550 3250 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6950 3650 50  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/kemet/C0603C104K5RACTU/399-5089-1-ND/1465623" H 6850 3100 50  0001 C CNN
F 4 "C0603C104K5RACTU" H 6975 3550 60  0001 C CNN "Part Number"
	1    6850 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR031
U 1 1 59C50BDB
P 6850 3550
F 0 "#PWR031" H 6850 3300 50  0001 C CNN
F 1 "GND" H 6850 3400 50  0000 C CNN
F 2 "" H 6850 3550 50  0000 C CNN
F 3 "" H 6850 3550 50  0000 C CNN
	1    6850 3550
	1    0    0    -1  
$EndComp
Text GLabel 8350 2800 1    60   Input ~ 0
3V3
Text Label 3500 2900 0    60   ~ 0
Temp-Humidty
Wire Wire Line
	3050 3200 3550 3200
Wire Wire Line
	3550 3300 3500 3300
Wire Wire Line
	4500 3300 4400 3300
Wire Wire Line
	4400 3200 4500 3200
Wire Wire Line
	3200 3250 3200 3200
Connection ~ 3200 3200
Wire Wire Line
	3200 3600 3200 3550
Wire Wire Line
	3500 3300 3500 3350
Wire Wire Line
	7900 3100 7900 3150
Wire Wire Line
	7900 3150 7850 3150
Wire Wire Line
	7900 3400 7900 3350
Wire Wire Line
	7900 3350 7850 3350
Wire Wire Line
	7150 3250 7150 3400
Wire Wire Line
	7150 3350 7200 3350
Wire Wire Line
	7200 3250 7150 3250
Connection ~ 7150 3350
Wire Wire Line
	7850 3250 8500 3250
Wire Wire Line
	6700 3150 7200 3150
Wire Wire Line
	6850 3200 6850 3150
Connection ~ 6850 3150
Wire Wire Line
	6850 3550 6850 3500
Wire Wire Line
	8350 2850 8350 2800
Text GLabel 8500 3250 2    60   Input ~ 0
LIGHT_INT
Wire Wire Line
	8350 3150 8350 3250
Connection ~ 8350 3250
$Comp
L R_10k R7
U 1 1 59C50BD9
P 8350 3000
F 0 "R7" V 8350 3000 50  0000 C CNN
F 1 "R_10k" V 8250 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8280 3000 50  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/yageo/RC0603JR-0710KL/311-10KGRCT-ND/729647" V 8430 3000 50  0001 C CNN
F 4 "RC0603JR-0710KL" V 8530 3100 60  0001 C CNN "Part Number"
	1    8350 3000
	-1   0    0    1   
$EndComp
$EndSCHEMATC