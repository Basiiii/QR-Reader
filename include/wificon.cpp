#include "wificon.h"

/*
 * Attempt to connect to the specified Wi-Fi network using the provided credentials.
 * This function will block until a connection is established.
 */
void connectToWiFi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // Connect to WiFi
  Serial.println();
  Serial.print("Connecting to Wi-Fi...");
  
  // Wait for Wi-Fi connection to be established
  while (WiFi.status() != WL_CONNECTED)
  {
      Serial.print(".");
      delay(300);
  }
  
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}
