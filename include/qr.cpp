#include "qr.h"

/*
 * Initialize the QR code reader and set it up for operation.
 * This function should be called once at the beginning of the program.
 */
void setupQRReader()
{
  Serial.print("Getting Schoolit ready...");
  reader.setup(); // Setup QR code reader
  reader.beginOnCore(1); // Begin QR on Core 1
}

/*
 * Continuously process QR codes from the reader and handle them as they are detected.
 * This function runs in an infinite loop and should be called after setupQRReader().
 */
void processQRCode()
{
  struct QRCodeData qrCodeData;
  while (true)
  {
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      Serial.print("Found QRCode");
      if (qrCodeData.valid)
      {
        handleValidQRCode(&qrCodeData);
      }
      else
      {
        Serial.println();
        Serial.print("Can't read QR code data.");
      }
    }
  }
}

/*
 * Handle a valid QR code by processing its payload and performing necessary actions.
 *
 * @param qrCodeData A pointer to the QRCodeData structure containing QR code information.
 */
void handleValidQRCode(QRCodeData* qrCodeData)
{
  Serial.print("Payload: ");
  Serial.println((const char *)qrCodeData->payload);
  
  dataMillis = millis();
  
  // Get current time and put it in correct format  
  String datetime_log = getCurrentTimeInCorrectFormat();
  
  // Setup and create document for Firebase
  setupAndCreateFirebaseDocument(qrCodeData, datetime_log);

  // Flash to confirm scan
  flashToConfirmScan();
}

/*
 * Initialize the camera and any necessary configurations.
 * This function should be called once at the beginning of the program.
 */
void setupCamera()
{
  Serial.print("Setting up camera...");
  pinMode(FLASH_GPIO_NUM, OUTPUT);
  // Optional camera configs can be placed here
  Serial.println();
}
