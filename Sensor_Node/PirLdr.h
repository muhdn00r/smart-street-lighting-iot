#ifndef PIRLDR_H
#define PIRLDR_H

#include <Arduino.h>
#include "PinDeclaration.h"
#include "LoRa.h"

void calibrationpir();
void handlePIR1(double* sistem);
void handleLDR1(double* sistem);
void handlePIR2(double* sistem);
void handleLDR2(double* sistem);
void handlePIR3(double* sistem);
void handleLDR3(double* sistem);
void systemrun();
void fadeled();

#endif