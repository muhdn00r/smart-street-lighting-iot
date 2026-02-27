#ifndef PIN_DECLARATION_H
#define PIN_DECLARATION_H

#include <Arduino.h>
#include "ProcData.h"
#include "SendData.h"

#define RX D8
#define TX D7

extern String data[13];
extern String payload;
extern String packet;
extern const char* ssid;
extern const char* password;
extern const char* server;

#endif