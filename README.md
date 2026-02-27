# IoT Smart Street Lighting: LoRa-to-WiFi Gateway

A modular C++ firmware for an ESP8266-based Gateway that bridges local sensor networks (LoRa) with cloud infrastructure (WiFi/HTTP). This system was developed as part of an Integrated Design Project (IDP) to optimize urban energy consumption through real-time motion detection and adaptive lighting.

## System Architecture
- Sensor Nodes: Distributed Arduino-based nodes detecting vehicle/pedestrian movement via PIR/Ultrasonic sensors.
- Communication: Long-range, low-power data transmission using LoRa (UART).
- Gateway (This Repo): An ESP8266 node that intercepts LoRa packets, parses the data, and forwards it to a centralized monitoring dashboard via RESTful API (HTTPS).

## Technical Highlights
- Modular C++ Architecture: Organized into PinDeclaration, ProcData, and SendData modules for high maintainability and separation of concerns.
- Hybrid Communication: Seamlessly bridges Serial/UART (LoRa) and TCP/IP (WiFi) stacks.
- Data Integrity: Implemented packet parsing and validation logic (ProcData) to ensure reliable data transmission from field sensors.
- Energy Optimization: Designed to support sensor-driven "Dimming-on-Idle" logic, reducing street lighting energy waste by up to 40%.

## Hardware and Protocols
- Microcontroller: ESP8266 (NodeMCU)
- Wireless: LoRa (OSOYOO UART Module), WiFi (802.11 b/g/n)
- Protocols: UART, HTTP/JSON, SPI
- Development: C++ (Arduino Framework)

## Project Structure
- final_upload_with_receive.ino: Main execution loop and hardware initialization.
- ProcData.cpp/h: Logic for parsing incoming LoRa packets and preparing JSON payloads.
- SendData.cpp/h: WiFi management and HTTP POST orchestration.
- PinDeclaration.h: Hardware abstraction layer for easy pin mapping.

---
Developed by Muhammad Noor Bin Nor Affandi
Computer Engineering Student | Universiti Teknikal Malaysia Melaka (UTeM)
