#include <SoftwareSerial.h>
#include "PinDeclaration.h"
#include "PirLdr.h"
#include "LoRa.h"
#include <Arduino.h>

// Global system state array
double sistem[13];

void setup() {
  Serial.begin(9600);

  // Initialize Sensor and LED Pins
  pinMode(PIR1, INPUT); 
  pinMode(PIR2, INPUT); 
  pinMode(PIR3, INPUT);
  
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT); 
  pinMode(LED5, OUTPUT); 
  pinMode(LED6, OUTPUT);

  // Initial setup: calibrate PIR and set LEDs to idle state
  fadeled();
  calibrationpir();
  
  Serial.println("System Initialized and Monitoring...");
}

void loop() {
  // Execute main sensor monitoring and communication logic
  systemrun();

  delay(1000); // Standard cycle delay
}