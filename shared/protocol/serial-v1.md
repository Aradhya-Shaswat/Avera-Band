# AVERA Arm V1 Protocol

Protocol Version: 1   
Status: Draft


## 1. Purpose

Define a consistent communication system b/w AVERA wearable hardware and AVERA Console

## 2. Transport

Development:
 - Arduino Uno over Serial USB
 - Baud rate: 115200
 - Encoding: UTF-8
 - Format: JSON
 
Production:
 - Seeed XIAO ESP32-C3
 - BLE (Bluetooth over low energy)
 - BLE Packet TBD

## 3. Device Identity

Development Device:
 - Device ID: AVERA-UNO-DEV
 - Hardware: Arduino Uno
 - Sensor: DHT11

Production Device:
 - Device ID: AVERA-ARM-ONE
 - Hardware: Seeed Studio XIAO ESP32-C3

## 4. Protocol Rules

 - Protocol Version is represented as `v`
 - Version 1 uses `v: 1`
 - Device Identity is represented by `device`
 - Device uptime is measured in milliseconds
 - Sequence numbers reset after reboot
 - Temperature values uses Celsius
 - Ambient/Skin temperature are distinct measurements.

## 5. Temperature Semantics

Development:
- DHT11
- Field: `ambient_temperature_c`

Production:
- TMP117
- Field: `skin_temperature_c`

These fields must never be treated as interchangeable.
