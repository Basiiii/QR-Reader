#include "firebase.h"

/*
 * Callback function for Firestore payload upload status.
 *
 * @param info Information about the upload status.
 */
void fcsUploadCallback(CFS_UploadStatusInfo info)
{
  // Handle various upload statuses
  switch(info.status)
  {
    case fb_esp_cfs_upload_status_init:
      Serial.printf("\nUploading data (%d)...\n", info.size);
      break;
    case fb_esp_cfs_upload_status_upload:
      Serial.printf("Uploaded %d%s\n", (int)info.progress, "%");
      break;
    case fb_esp_cfs_upload_status_complete:
      Serial.println("Upload completed ");
      break;
    case fb_esp_cfs_upload_status_process_response:
      Serial.print("Processing the response... ");
      break;
    case fb_esp_cfs_upload_status_error:
      Serial.printf("Upload failed, %s\n", info.errorMsg.c_str());
      break;
  }
}

/*
 * Initialize and set up the Firebase client configuration.
 */
void setupFirebase()
{
  // Display FIREBASE version
  Serial.println();
  Serial.printf("Firebase client v%s\n\n", FIREBASE_CLIENT_VERSION);
  
  // Assign the API key (required)
  firebaseconfig.api_key = API_KEY;
  
  // Assign the user sign-in credentials
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  
  // Assign the callback function for the long-running token generation task
  firebaseconfig.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  
  // Limit the size of response payload to be collected in FirebaseData
  fbdo.setResponseSize(2048);
  
  // Begin Firebase connection
  Firebase.begin(&firebaseconfig, &auth);
}

/*
 * Start the Firebase connection and reconnect if WiFi connection is lost.
 */
void startFirebase()
{
  // Reconnect if WiFi connection is lost
  Firebase.reconnectWiFi(true);
  
  // For sending payload callback
  // config.cfs.upload_callback = fcsUploadCallback;
}

/*
 * Set up and create a Firestore document in Firebase.
 *
 * @param qrCodeData A pointer to the QRCodeData structure.
 * @param datetime_log The timestamp to be used in the document path.
 */
void setupAndCreateFirebaseDocument(QRCodeData* qrCodeData, String datetime_log)
{
  FirebaseJson content;
  String documentPath = "SCHOOL_NAME/" + datetime_log;
  
  // Set fields in the Firestore document
  content.set("fields/dateTime/timestampValue", String(datetime_log) + String("Z"));
  content.set("fields/uid/stringValue", String((const char *)qrCodeData->payload));

  // Create document in Firebase
  Serial.print("Creating a document... ");
  
  if (Firebase.Firestore.createDocument(&fbdo, FIREBASE_PROJECT_ID, "" /* databaseId can be (default) or empty */, documentPath.c_str(), content.raw()))
      Serial.printf("Document created:\n\n%s\n\n", fbdo.payload().c_str());
  else
      Serial.println(fbdo.errorReason());
}
