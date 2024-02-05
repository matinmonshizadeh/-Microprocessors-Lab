# Microprocessors-Lab

## Session 1
![Session1](https://github.com/matinmonshizadeh/-Microprocessors-Lab/assets/96329489/1c8507e4-353f-4977-8f99-3ffa501369c5)


## Session 2
![photo_5873051543589207414_y](https://github.com/matinmonshizadeh/-Microprocessors-Lab/assets/96329489/bfc8e9b2-8c22-4574-a2ea-c437220380f7)
![photo_5900040525371784542_y](https://github.com/matinmonshizadeh/-Microprocessors-Lab/assets/96329489/8abc4bd1-3ce8-49d1-9cd7-b4cb4ee96b85)


## Session 3
![photo_5900040525371784543_y](https://github.com/matinmonshizadeh/-Microprocessors-Lab/assets/96329489/5534a41d-c1cc-4067-9f40-34faebf92c42)

## Final Project
### ESP32 Door Control System

This project implements a door control system using the ESP32 microcontroller. The system provides two modes of operation: Auto and Manual. In Auto mode, the door opens and closes based on light intensity monitored by an LDR sensor. In Manual mode, the door can be controlled using a mobile phone panel.

### Description

The ESP32 Door Control System is designed to automate the process of opening and closing a door. It utilizes MQTT for communication and consists of two main components: the ESP32 microcontroller and a mobile phone panel. The system includes features for automatic operation based on light conditions and manual control via MQTT commands.

### Features

#### Auto Mode

- The system automatically opens the door when the light intensity falls below a certain threshold.
- The door closes when the light intensity rises above another threshold.
- Light intensity values are transmitted to the MQTT broker.

#### Manual Mode

- Manual control of the door through MQTT commands from a mobile phone panel.
- Supports commands like "open" and "close" to control the door.

### Setup Instructions

1. Connect the ESP32 to your Wi-Fi network by providing the SSID and password.
2. Set up the MQTT broker address in the code.
3. Connect an LDR sensor to monitor light intensity.
4. Flash the code to the ESP32.

### Usage

1. After connecting to Wi-Fi, the ESP32 establishes communication with the MQTT broker.
2. In Auto mode, the door operates based on light intensity values from the LDR sensor.
3. In Manual mode, the door can be controlled using MQTT commands from a mobile phone panel.

### Dependencies

- [Arduino](https://www.arduino.cc/)
- [WiFi library](https://www.arduino.cc/en/Reference/WiFi)
- [PubSubClient library](https://pubsubclient.knolleary.net/)
