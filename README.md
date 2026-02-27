# IoT Smart Street Lighting: Full-Stack Embedded System

This repository contains the complete firmware for a smart urban lighting system developed as an Integrated Design Project (IDP). The system uses a multi-node architecture to optimize energy consumption through real-time motion detection and adaptive dimming.

## System Overview

The project is divided into two primary components:

### 1. Sensor Node (Arduino)
Located in the `Sensor_Node/` directory, this firmware runs on distributed Arduino nodes equipped with PIR motion sensors and LDR light sensors.
- Motion Detection: Monitors vehicle and pedestrian movement.
- Local Processing: Analyzes environmental light levels to determine if lighting is required.
- Communication: Transmits sensor data to the Gateway via LoRa (Long Range) wireless protocol.

### 2. Gateway Node (ESP8266)
Located in the `Gateway_Node/` directory, this firmware runs on a central ESP8266 node that bridges the local sensor network to the cloud.
- LoRa Reception: Intercepts and parses data packets from multiple Sensor Nodes.
- WiFi Connectivity: Connects to local network infrastructure.
- Cloud Integration: Forwards processed data to a centralized monitoring dashboard via RESTful API (HTTPS).

## Technical Features
- Multi-Protocol Bridge: Seamlessly integrates LoRa (UART) and WiFi (TCP/IP) communication stacks.
- Modular C++ Design: Uses object-oriented principles to separate hardware abstraction, data processing, and communication logic.
- Energy Optimization: Supports sensor-driven dimming logic to reduce energy waste during idle periods.
- Reliable Data Parsing: Implemented robust packet validation to ensure data integrity across wireless links.

## Hardware and Technologies
- Microcontrollers: ESP8266 (NodeMCU), Arduino Uno/Nano.
- Wireless: LoRa (OSOYOO UART Module), WiFi (802.11 b/g/n).
- Protocols: UART, HTTP, JSON, SPI.
- Development Environment: C++ (Arduino Framework).

---
Developed by Muhammad Noor | Afif Amran | Shazriena
Computer Engineering Student | Universiti Teknikal Malaysia Melaka (UTeM)
