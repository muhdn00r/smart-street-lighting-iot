#include "SendData.h"
#include "PinDeclaration.h"

// Function to send processed sensor data to a centralized server via HTTP POST
void sendMotionData(String payload) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Start connection to the specified server
    http.begin(client, server);
    
    // Set headers for JSON payload
    http.addHeader("Content-Type", "application/json");

    // Send HTTP POST request with sensor payload
    int httpResponseCode = http.POST(payload);

    // Provide feedback based on response code
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }

    // Close connection to free resources
    http.end();
  } else {
    Serial.println("WiFi Disconnected. Unable to send data.");
  }
}
