#include "ProcData.h"
#include "PinDeclaration.h"

String buffer = ""; // Buffer to store incoming data

void clearData() {
  for (int i = 0; i < 13; i++) {
    data[i] = ""; // Reset each element to an empty string
  }
}

// Function to process a single packet
void processPacket(String packet) {
  clearData();
  // Ensure the packet is not empty
  if (packet.length() > 0) {
    int index = 0;

    // Split the packet by commas and store in the data array
    while (packet.length() > 0 && index < 13) {
      int commaIndex = packet.indexOf(',');
      if (commaIndex == -1) { // Last value
        data[index++] = packet;
        break;
      } else {
        data[index++] = packet.substring(0, commaIndex);
        packet = packet.substring(commaIndex + 1);
      }
    }

    // Check if the correct number of fields was parsed
    if (index == 13) {
      // Construct the JSON payload
      payload = "{";
      payload += "\"pir\":[" + data[1] + "," + data[2] + "," + data[3] + "],";
      payload += "\"ldr\":[" + data[4] + "," + data[5] + "," + data[6] + "],";
      payload += "\"led\":[" + data[7] + "," + data[8] + "," + data[9] + ","
                 + data[10] + "," + data[11] + "," + data[12] + "],";
      payload += "\"voltage\":" + data[0];
      payload += "}";

      // Print the parsed JSON
      Serial.println("Parsed JSON:");
      Serial.println(payload);
    } else {
      Serial.println("Invalid packet format: Incorrect number of fields.");
    }
  } else {
    Serial.println("Invalid packet format: Empty packet.");
  }
}

// Function to parse incoming data
void ProcData(String incomingData) {
  // Append incoming data to the buffer
  buffer += incomingData;

  // Process all complete packets
  int delimiterIndex;
  while ((delimiterIndex = buffer.indexOf('\n')) != -1) { // Assume '\n' as the delimiter
    String packet = buffer.substring(0, delimiterIndex); // Extract one packet
    buffer = buffer.substring(delimiterIndex + 1);       // Remove processed packet
    processPacket(packet);                               // Process the extracted packet
  }
}
