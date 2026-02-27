#ifndef SEND_DATA_H
#define SEND_DATA_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include "PinDeclaration.h"
#include "ProcData.h"

void sendMotionData(String payload);

#endif