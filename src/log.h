#pragma once
#include <Arduino.h>
#ifdef ARDUINO_USB_MODE
#define LOG_UART USBSerial.printf
#define LOG_INIT USBSerial.begin
#else
#define LOG_UART Serial.printf
#define LOG_INIT Serial.begin
#endif