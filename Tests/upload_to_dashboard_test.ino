#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "ssid";         // Replace with your Wi-Fi SSID
const char* password = "password"; // Replace with your Wi-Fi Password
const char* server = "ip address";
const char* serverUrl = "ip address:3000/api/sensors"; // Replace with your server IP and port

WiFiClient client;
HTTPClient http;

String packet = "Starting Packet,0.00,1,1,0,28,0,0,51,51,51,51,255,255,Packet End";
//  int randomldr, randompir, randomled, randompower, pir1, pir2, pir3, ldr1, ldr2, ldr3, led1Brightness, led2Brightness, led3Brightness, led4Brightness, led5Brightness,
// led6Brightness, powerConsumption;

void setup() {
  Serial.begin(9600);

  // pinMode(PIR1, INPUT);
  // pinMode(PIR2, INPUT);
  // pinMode(PIR3, INPUT);
  // pinMode(LED1, OUTPUT);
  // pinMode(LED2, OUTPUT);
  // pinMode(LED3, OUTPUT);

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
  // int randomldr = random(100, 400);
  // int randompir = random(0,10)/10;
  // int randomled = random(0, 256);
  // int randompower = random(0, 1000);
  // // Control LED based on sensor input
  // int pir1 = random(0, 2);;
  // int pir2 = random(0, 2);;
  // int pir3 = random(0, 2);;
  // int ldr1 = random(100, 400);
  // int ldr2 = random(100, 400);
  // int ldr3 = random(100, 400);
  // int led1Brightness = random(0, 256);
  // int led2Brightness = random(0, 256);
  // int led3Brightness = random(0, 256);
  // int led4Brightness = random(0, 256);
  // int led5Brightness = random(0, 256);
  // int led6Brightness = random(0, 256);
  // int powerConsumption = randompower;

  // Send data to server if there's any change
  sendMotionData(packet);

  delay(3000); // Send data every second (adjust if necessary)
}

void sendMotionData(String packet) {
    
    if (packet.startsWith("Starting Packet") && packet.endsWith("Packet End")) {
        packet.replace("Starting Packet,", "");
        packet.replace(",Packet End", "");
        
        // Split the packet by commas
        String data[14];
        int index = 0;
        while (packet.length() > 0) {
            int commaIndex = packet.indexOf(',');
            if (commaIndex == -1) {  // Last value
                data[index++] = packet;
                break;
            }
            data[index++] = packet.substring(0, commaIndex);
            packet = packet.substring(commaIndex + 1);
        }
    
        // Prepare JSON data
        String payload = "{";
        payload += "\"pir\":[" + data[1] + "," + data[2] + "," + data[3] + "],";
        payload += "\"ldr\":[" + data[4] + "," + data[5] + "," + data[6] + "],";
        payload += "\"led\":[" + data[7] + "," + data[8] + "," + data[9] + ","
                               + data[10] + "," + data[11] + "," + data[12] + "],";
        payload += "\"voltage\":" + data[0];
        payload += "}";
        Serial.println(payload);

  Serial.println("\nStarting connection to server...");
  if (http.begin(client, serverUrl)) {
    Serial.println("HTTP connection established!");
    http.addHeader("Content-Type", "application/json");
      
    int httpResponseCode = http.POST(payload);
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Data sent successfully!");
      Serial.print("Server response: ");
      Serial.println(response);
    } else {
        Serial.print("Error sending data. HTTP response code: ");
        Serial.println(httpResponseCode);
        String errorDetails = http.errorToString(httpResponseCode);
        Serial.print("Error: ");
        Serial.println(errorDetails);
      }
  http.end();
  } else {
      Serial.println("HTTP connection failed!");
    }
}
}

