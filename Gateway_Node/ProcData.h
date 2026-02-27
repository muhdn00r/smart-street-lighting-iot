#ifndef PROC_DATA_H
#define PROC_DATA_H

#include <Arduino.h>

// Function declarations for processing incoming LoRa data
void clearData();
void processPacket(String packet);
void ProcData(String incomingData);

#endif
