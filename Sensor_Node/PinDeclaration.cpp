#include "PinDeclaration.h"

int a = 5;

void getBatteryVoltage(double* sistem) {
  // int R1 = 10000;
  // int R2 = 10000;
  // int sensorValue = analogRead(analogPin);
  // float voltage = sensorValue * (5.0 / 1023.0);

  // // Calculate the battery voltage
  // float batteryVoltage = voltage * (R1 + R2) / R2;

  // Serial.print("Battery Voltage: ");
  // Serial.print(batteryVoltage);
  // Serial.println(" V");
  // sistem[Abatt] = batteryVoltage;
  sistem[Abatt] = a;
}