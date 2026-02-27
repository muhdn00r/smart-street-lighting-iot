#ifndef PROC_DATA_H
#define PROC_DATA_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "PinDeclaration.h"
#include "SendData.h"

void clearData();
void processPacket(String packet);
void ProcData(String incomingData);

#endif