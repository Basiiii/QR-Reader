#include "datetime.h"

/*
 * Initializes the DateTime library and sets up the time server and time zone.
 * This function should be called once at the beginning of the program.
 */
void setupDateTime() 
{
  Serial.print("Setting up datetime...");
  Serial.println();

  // Set the time server and time zone for DateTime.
  DateTime.setServer("time.pool.aliyun.com");
  DateTime.setTimeZone("CST-8");
  DateTime.begin();

  // Check if the time is valid and print the date if available.
  if (!DateTime.isTimeValid()) 
  {
      Serial.println("Failed to get time from server.");
  } 
  else 
  {
      Serial.printf("Date now is: %s\n", DateTime.toISOString().c_str());
  }
}

/*
 * Initializes the UDP client for time synchronization.
 * This function should be called after setupDateTime() to start the UDP client.
 */
void startUDPClient()
{
  timeClient.begin(); // Starts the underlying UDP client with the default local port
}

/*
 * Retrieves the current time in the correct format and returns it as a string.
 * The returned string is in ISO 8601 format without the seconds and timezone offset.
 *
 * @return A string containing the current time in the correct format.
 */
String getCurrentTimeInCorrectFormat()
{
  // Format the current time in ISO 8601 format and remove the seconds part.
  String datetime_log = String(DateTime.formatUTC(DateFormatter::ISO8601).c_str());
  datetime_log.remove(datetime_log.length() - 5);
  return datetime_log;
}
