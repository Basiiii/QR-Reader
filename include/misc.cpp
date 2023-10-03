#include "misc.h"

/*
 * Initialize the serial communication at a baud rate of 115200.
 * This function should be called once at the beginning of the program.
 */
void setupSerial()
{
  Serial.begin(115200);
  Serial.println();
}

/*
 * Print a ready message to the serial console to indicate that the QR reader is online and ready.
 * This function can be called to provide status information.
 */
void printReadyMessage()
{
  Serial.println();
  Serial.print("Schoolit QR reader is online and ready.");
  Serial.println();
}

/*
 * Flash an LED to confirm a scan or an action.
 * This function temporarily sets the specified GPIO pin to HIGH for a short duration.
 */
void flashToConfirmScan()
{
  digitalWrite(FLASH_GPIO_NUM, HIGH);
  delay(200);
  digitalWrite(FLASH_GPIO_NUM, LOW);
  delay(500);
}
