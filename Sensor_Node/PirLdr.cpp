#include "PirLdr.h"

int PIRValue1 = 0;
int PIRValue2 = 0;
int PIRValue3 = 0;
int PIRState1 = 0;
int PIRState2 = 0;
int PIRState3 = 0;

int LDR1, LDR2, LDR3;
int calibrationTime = 30;

void calibrationpir() {
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
}

void handlePIR1(double* sistem) {
  Serial.println("Motion1 Detected");
  analogWrite(LED1, Hpercent);
  sistem[Aled1] = Hpercent;
  analogWrite(LED2, Hpercent);
  sistem[Aled2] = Hpercent;
  analogWrite(LED3, Hpercent);
  sistem[Aled3] = Hpercent;
  analogWrite(LED4, Hpercent);
  sistem[Aled4] = Hpercent;
  analogWrite(LED5, Hpercent);
  sistem[Aled5] = Hpercent;
  analogWrite(LED6, Hpercent);
  sistem[Aled6] = Hpercent;
  LoRaSend(sistem);

  delay(intervalPIR);
  analogWrite(LED1, Lpercent);
  sistem[Aled1] = Lpercent;
  LoRaSend(sistem);
  delay(intervalPIR);
  analogWrite(LED2, Lpercent);
  sistem[Aled2] = Lpercent;
  LoRaSend(sistem);
  Serial.println("Motion1 Ended");
}

void handleLDR1(double* sistem) {
  Serial.println("LDR1 Detected");
  analogWrite(LED1, Hpercent);
  sistem[Aled1] = Hpercent;
  analogWrite(LED2, Hpercent);
  sistem[Aled2] = Hpercent;
  analogWrite(LED3, Hpercent);
  sistem[Aled3] = Hpercent;
  analogWrite(LED4, Hpercent);
  sistem[Aled4] = Hpercent;
  analogWrite(LED5, Hpercent);
  sistem[Aled5] = Hpercent;
  analogWrite(LED6, Hpercent);
  sistem[Aled6] = Hpercent;
  LoRaSend(sistem);
  delay(intervalLDR);
  analogWrite(LED1, Lpercent);
  sistem[Aled1] = Lpercent;
  LoRaSend(sistem);
  delay(intervalLDR);
  analogWrite(LED2, Lpercent);
  sistem[Aled2] = Lpercent;
  LoRaSend(sistem);
  Serial.println("LDR1 Ended");
}

void handlePIR2(double* sistem) {
  Serial.println("Motion2 Detected");
  analogWrite(LED3, Hpercent);
  sistem[Aled3] = Hpercent;
  analogWrite(LED4, Hpercent);
  sistem[Aled4] = Hpercent;
  LoRaSend(sistem);
  delay(intervalPIR);
  analogWrite(LED3, Lpercent);
  sistem[Aled3] = Lpercent;
  LoRaSend(sistem);
  delay(intervalPIR);
  analogWrite(LED4, Lpercent);
  sistem[Aled4] = Lpercent;
  LoRaSend(sistem);
  Serial.println("Motion2 Ended");
}

void handleLDR2(double* sistem) {
  Serial.println("LDR2 Detected");
  analogWrite(LED3, Hpercent);
  sistem[Aled3] = Hpercent;
  analogWrite(LED4, Hpercent);
  sistem[Aled4] = Hpercent;
  LoRaSend(sistem);
  delay(intervalLDR);
  analogWrite(LED3, Lpercent);
  sistem[Aled3] = Lpercent;
  delay(intervalLDR);
  analogWrite(LED4, Lpercent);
  sistem[Aled4] = Lpercent;
  LoRaSend(sistem);
  Serial.println("LDR2 Ended");
}

void handlePIR3(double* sistem) {
  Serial.println("Motion3 Detected");
  analogWrite(LED5, Hpercent);
  sistem[Aled5] = Hpercent;
  analogWrite(LED6, Hpercent);
  sistem[Aled6] = Hpercent;
  delay(intervalPIR);
  analogWrite(LED5, Lpercent);
  sistem[Aled5] = Lpercent;
  delay(intervalPIR);
  analogWrite(LED6, Lpercent);
  sistem[Aled6] = Lpercent;
  LoRaSend(sistem);
  Serial.println("Motion3 Ended");
}

void handleLDR3(double* sistem) {
  Serial.println("LDR3 Detected");
  analogWrite(LED5, Hpercent);
  sistem[Aled5] = Hpercent;
  analogWrite(LED6, Hpercent);
  sistem[Aled6] = Hpercent;
  LoRaSend(sistem);
  delay(intervalLDR);
  analogWrite(LED5, Lpercent);
  sistem[Aled5] = Lpercent;
  LoRaSend(sistem);
  delay(intervalLDR);
  analogWrite(LED6, Lpercent);
  sistem[Aled6] = Lpercent;
  LoRaSend(sistem);
  Serial.println("LDR3 Ended");
}

void systemrun() {
  PIRValue1 = digitalRead(PIR1);
  LDR1 = analogRead(A0);
  Serial.print("LDR 1: ");
  Serial.println(LDR1);

  if (PIRValue1 == HIGH || LDR1 < threshold1) {
    if (PIRValue1 == HIGH) {
      sistem[Apir1] = 1;
      sistem[Apir2] = 0;
      sistem[Apir3] = 0;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handlePIR1(sistem);
    }
    if (LDR1 < threshold1) {
      sistem[Apir1] = PIRValue1;
      sistem[Apir2] = PIRValue2;
      sistem[Apir3] = PIRValue3;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handleLDR1(sistem);
    }
  }

  PIRValue2 = digitalRead(PIR2);
  LDR2 = analogRead(A1);
  Serial.print("LDR 2: ");
  Serial.println(LDR2);

  if (PIRValue2 == HIGH || LDR2 < threshold2) {
    if (PIRValue2 == HIGH) {
      sistem[Apir1] = 0;
      sistem[Apir2] = 1;
      sistem[Apir3] = 0;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handlePIR2(sistem);
    }
    if (LDR2 < threshold2) {
      sistem[Apir1] = PIRValue1;
      sistem[Apir2] = PIRValue2;
      sistem[Apir3] = PIRValue3;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handleLDR2(sistem);
    }
  }

  PIRValue3 = digitalRead(PIR3);
  LDR3 = analogRead(A2);
  Serial.print("LDR 3: ");
  Serial.println(LDR3);

  if (PIRValue3 == HIGH || LDR3 < threshold3) {
    if (PIRValue3 == HIGH) {
      sistem[Apir1] = 0;
      sistem[Apir2] = 0;
      sistem[Apir3] = 1;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handlePIR3(sistem);
    }
    if (LDR3 < threshold3) {
      sistem[Apir1] = PIRValue1;
      sistem[Apir2] = PIRValue2;
      sistem[Apir3] = PIRValue3;
      sistem[Aldr1] = LDR1;
      sistem[Aldr2] = LDR2;
      sistem[Aldr3] = LDR3;
      handleLDR3(sistem);
    }
  }

}

void fadeled() {
  analogWrite(LED1, Lpercent);
  analogWrite(LED2, Lpercent);
  analogWrite(LED3, Lpercent);
  analogWrite(LED4, Lpercent);
  analogWrite(LED5, Lpercent);
  analogWrite(LED6, Lpercent);
}