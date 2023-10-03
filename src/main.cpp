/**
 * ESP32-CAM QR reader and Firebase Firestore database logger
 * for the Schoolit project
 * 
 * Developed by: Enrique Rodrigues
 * Email: basigraphics@gmail.com
 * Github: https://github.com/Basiiii
 * 
 * Copyright (c) 2022 Basi
 * 
 * Additional notes:
 * Firebase database access operations require Email/Password, custom or OAUth2.0 authentication.
 * Datetime is done through an NTP - "time.pool.aliyun.com".
 * Database access and NTP access require Wifi connection.
 */

#include <Arduino.h>

#include <NTPClient.h>

#include <ESP32QRCodeReader.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>

#include <ArduinoJson.h>

#include "ESPDateTime.h"
#include "esp_camera.h"
#include "config.h"

#include "datetime.h"
#include "firebase.h"
#include "qr.h"
#include "wificon.h"
#include "misc.h"

#define FLASH_GPIO_NUM 4 // flashlight ESP32

// WIFI connection is required for database & NTP server
#define WIFI_SSID "SSID_GOES_HERE"
#define WIFI_PASSWORD "WIFI_PASSWORD_GOES_HERE"

// Firebase required details
#define API_KEY "API_KEY_GOES_HERE"
#define FIREBASE_PROJECT_ID "FIREBASE_PROJECT_ID_GOES_HERE"

// Official Schoolit account used as Auth
#define USER_EMAIL "EMAIL_GOES_HERE"
#define USER_PASSWORD "PASSWORD_GOES_HERE"

// Ensure required constants are defined
#if !defined(WIFI_SSID) || !defined(WIFI_PASSWORD)
#error "WiFi SSID and Password must be defined."
#endif

#if !defined(API_KEY) || !defined(FIREBASE_PROJECT_ID)
#error "API key and Firebase Project ID must be defined."
#endif

#if !defined(USER_EMAIL) || !defined(USER_PASSWORD)
#error "User email and password must be defined."
#endif

// Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig firebaseconfig;
ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

unsigned long dataMillis = 0;
unsigned long lastMs = 0;
unsigned long ms = millis();

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup()
{
  setupSerial();
  setupCamera();
  setupQRReader();
  connectToWiFi();
  setupFirebase();
  setupDateTime();
  startFirebase();
  startUDPClient();
  printReadyMessage();
}

void loop()
{
  processQRCode();
}
