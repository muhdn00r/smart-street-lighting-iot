#ifndef PIN_DECLARATION_H
#define PIN_DECLARATION_H

#include <Arduino.h>

// Software Serial Pins for LoRa
#define RX D8
#define TX D7

// External variables used across modules
extern String data[13];
extern String payload;
extern String packet;
extern const char* ssid;
extern const char* password;
extern const char* server;

#endif
