#include "PinDeclaration.h"

// WiFi Credentials - Replace with your network information
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Server Configuration - Replace with your monitoring dashboard URL
const char* server = "http://your-monitoring-dashboard.com/api/data";

// Global variables for data handling
String data[13];
String payload = "";
String packet = "";
