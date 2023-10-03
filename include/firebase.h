#pragma once

#ifndef FIREBASE_H
#define FIREBASE_H

void fcsUploadCallback(CFS_UploadStatusInfo info);
void setupFirebase();
void startFirebase();
void setupAndCreateFirebaseDocument(QRCodeData* qrCodeData, String datetime_log);

#endif
