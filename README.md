# QR Code Reader for ESP-32-CAM

This is a QR code reader built for the Schoolit project, intended to be implemented in the ESP-32-CAM module by Espressif Systems.

## Description

This QR code reader was specifically designed for the ESP-32-CAM module by Espressif. Its primary function is to capture and decode QR codes, allowing seamless integration with the Schoolit project. The project's main objective is to provide students with an efficient way to mark their attendance using their smartphones.

## Key Features:
- **ESP-32-CAM Compatibility:** Tailored to work seamlessly with the ESP-32-CAM microcontroller, leveraging its dual-core power and built-in wireless capabilities.

- **QR Code Scanning:** The reader is equipped with the ability to scan QR codes swiftly, making it ideal for applications where quick data capture is essential.

- **Firebase Integration:** Captured QR code data is securely stored and managed using Firebase Firestore, ensuring real-time access and data consistency.

- **Schoolit Project:** This QR code reader was developed as an integral part of the Schoolit project, contributing to the creation of a modern attendance tracking system that students can conveniently access via their smartphones.

By combining the capabilities of the ESP-32-CAM with QR code scanning and Firebase storage, this project simplifies attendance tracking and enhances the overall efficiency of the Schoolit project.

## Authors

Enrique Rodrigues (Basi)

## Version History

* 0.1
    * Working QR reader
* 0.2
    * Implemented Firebase Connection
* 0.3
    * Expanded Firebase Logging
* 0.4
    * Removed Count Feature
* 1.0
    * Fully Functional Release
* 2.0
    * Major Performance Improvement

## Acknowledgments

Inspiration, code snippets, etc.
* [github.com (esp32)](https://github.com/espressif/arduino-esp32)
* [github.com (esp32 firebase)](https://github.com/mobizt/Firebase-ESP32)
* [github.com (esp32 qr code reader)](https://github.com/alvarowolfx/ESP32QRCodeReader)
