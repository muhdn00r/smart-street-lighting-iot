#ifndef PIN_DECLARATION_H
#define PIN_DECLARATION_H

#include <Arduino.h>

// PIR Sensor Pins
#define PIR1 2
#define PIR2 3
#define PIR3 4

// LED Output Pins (PWM recommended)
#define LED1 5
#define LED2 6
#define LED3 9
#define LED4 10
#define LED5 11
#define LED6 12

// Software Serial for LoRa
#define RX 7
#define TX 8

// System Constants
const int Hpercent = 255;  // 100% Brightness
const int Lpercent = 50;   // ~20% Brightness (Idle)
const int intervalPIR = 5000;
const int intervalLDR = 5000;
const int threshold1 = 400;
const int threshold2 = 400;
const int threshold3 = 400;

// System Array Indices
enum SystemIndices {
  Abatt = 0,
  Apir1, Apir2, Apir3,
  Aldr1, Aldr2, Aldr3,
  Aled1, Aled2, Aled3, Aled4, Aled5, Aled6
};

#endif
