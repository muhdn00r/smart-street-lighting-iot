#include "LoRa.h"

SoftwareSerial LoRa (RX, TX);

void LoRaSend(double* sistem) {
  double num = 5;
  LoRa.begin(9600);
  // num = sistem[Abatt];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Apir1];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Apir2];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Apir3];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aldr1];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aldr2];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aldr3];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled1];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled2];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled3];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled4];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled5];
  LoRa.print(num); LoRa.print(",");
  num = sistem[Aled6];
  LoRa.print(num); LoRa.println();
}
