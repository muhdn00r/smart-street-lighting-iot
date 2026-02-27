#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include "PinDeclaration.h"
#include "ProcData.h"
#include "SendData.h"

SoftwareSerial LoRa (TX, RX);

String packet;

void setup() {
  Serial.begin(9600);
  LoRa.begin(9600);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print the IP address
}

void loop() {
  if(LoRa.available() > 0){//Read from  OSOYOO UART LoRa wireless module and send to serial monitor
        packet = LoRa.readString();
        Serial.println(packet);
        ProcData(packet);
  // Send data to server if there's any change
  
  sendMotionData(payload);    
  }

  delay(10); // Send data every second (adjust if necessary)
}
