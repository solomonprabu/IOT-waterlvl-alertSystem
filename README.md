# IOT-waterlvl-alertSystem

## Project Description

The "IOT-waterlvl-alertSystem" is a smart water level monitoring system designed to alert the user both locally and remotely when the water level in a container (like a tank or well) falls below a critical threshold (indicating the water is low) or rises to an overflow level.

* **Local Alert:** A local buzzer sounds an audible alarm.
* **Remote Alert (IoT):** A notification (e.g., SMS, email, or push notification) is sent to the user via the IFTTT (If This Then That) web service.

The system uses an HC-SR04 Ultrasonic Sensor, placed above the water source, to measure the distance to the water surface. A small distance indicates a high water level, and a large distance indicates a low water level.

## Components Required

* **Microcontroller:** NodeMCU ESP8266 Development Board (or similar ESP8266 board)
* **Sensor:** HC-SR04 Ultrasonic Sensor Module
* **Actuator:** Active or Passive Buzzer
* **Safety Component:** 1 x 1kΩ Resistor, 1 x 2kΩ Resistor (for voltage divider)
* **Connectivity:** Breadboard, Jumper Wires, Micro-USB Cable (for power and programming)

## Hardware Setup (Circuit)

The NodeMCU is a 3.3V logic device, while the HC-SR04 sensor runs on 5V and outputs a 5V signal. A voltage divider is mandatory to protect the NodeMCU's digital input pin.

### Connection Table

| Component | Component Pin | NodeMCU ESP8266 Pin | Notes |
| :--- | :--- | :--- | :--- |
| **Ultrasonic Sensor** | VCC | Vin | 5V Power Supply |
| **Ultrasonic Sensor** | GND | GND | Common Ground |
| **Ultrasonic Sensor** | TRIG | D5 (GPIO14) | Output from NodeMCU (Trigger Pulse) |
| **Ultrasonic Sensor** | ECHO | Voltage Divider Input -> D6 (GPIO12) | Input to NodeMCU (Reads Pulse Duration) |
| **Buzzer** | Positive (+) | D7 (GPIO13) | Output from NodeMCU (Local Alert) |
| **Buzzer** | Negative (-) | GND | Common Ground |

### Voltage Divider Configuration

* Connect HC-SR04 **ECHO** pin to one end of a **1kΩ resistor (R1)**.
* Connect the other end of **R1** to the **D6 (GPIO12)** pin.
* Connect the **D6 (GPIO12)** pin to one end of a **2kΩ resistor (R2)**.
* Connect the other end of **R2** to **GND**.

## Hardware Setup
![circuit_diagram](https://github.com/solomonprabu/IOT-waterlvl-alertSystem/blob/main/circuit_diagram.png)

## Software Setup

### 1. Arduino IDE Setup

* Install the ESP8266 board package in your Arduino IDE.
* Select the correct board (e.g., "NodeMCU 1.0 (ESP-12E Module)") and Port.
* The provided code uses the built-in `ESP8266WiFi.h` library, so no additional library installation is required.

### 2. IFTTT Setup

This project requires a connection to the IFTTT web service to send the remote alert.

1.  Create an IFTTT account and enable the **Webhooks** and **SMS/Notification** services.
2.  Create an IFTTT Applet:
    * **IF THIS:** Select **Webhooks** as the service, and choose the trigger **"Receive a web request."**
    * Set the **Event Name** (e.g., `water_alert`).
    * **THEN THAT:** Select the desired notification service (e.g., **SMS** or **Notifications**) and customize the message.
3.  Go to the Webhooks service documentation page to find your **Maker Key**.
4.  Update the following lines in the `NodeMCU - mod.ino` code with your specific details:

```cpp
const char *ssid = "Solo";          // Replace with your WiFi SSID
const char *pass = "qwer1234";      // Replace with your WiFi Password
String url = "/trigger/sms/json/with/key/g_QjutMSaJeHKkyxU5szX1sEzSCSlTGb_0XJNiuHnhW"; 
// Replace 'sms' with your IFTTT event name (e.g., 'water_alert') 
// and replace the key with your actual Maker Key.
