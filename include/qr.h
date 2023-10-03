#pragma once

#ifndef QR_H
#define QR_H

void setupQRReader();
void processQRCode();
void handleValidQRCode(QRCodeData* qrCodeData);
void setupCamera();

#endif
