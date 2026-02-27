#ifndef SEND_DATA_H
#define SEND_DATA_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

// Function declaration for sending data to the cloud
void sendMotionData(String payload);

#endif
