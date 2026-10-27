# IoT Sensor Monitoring Using Arduino UNO, ESP8266 and Blynk

## 📌 Project Overview

This project is an IoT-based sensor monitoring system using an Arduino UNO and an ESP8266 NodeMCU. It monitors temperature, humidity, gas levels, and light intensity using three sensors.

The Arduino UNO collects data from the sensors and sends it to the ESP8266 NodeMCU using **SoftwareSerial communication**. The NodeMCU connects to Wi-Fi and uploads the sensor readings to the **Blynk IoT platform**, allowing users to monitor the values through a mobile app.

## ✨ Features

* Temperature monitoring using DHT11.
* Humidity monitoring using DHT11.
* Gas detection using the MQ-2 sensor.
* Light monitoring using an LDR sensor.
* Serial communication between Arduino UNO and ESP8266.
* Wireless sensor data monitoring through the Blynk app.
* Real-time display of sensor readings.

## 🛠️ Hardware Requirements

* Arduino UNO
* ESP8266 NodeMCU
* DHT11 temperature and humidity sensor
* MQ-2 gas sensor module
* LDR sensor module with analog output
* Breadboard
* Jumper wires
* 1 kΩ resistor
* 2 kΩ resistor
* USB cables and suitable power supplies

## 💻 Software Requirements

* Arduino IDE
* ESP8266 board package for Arduino IDE
* DHT11 library providing `DHT11.h`
* Blynk library
* Blynk account
* Wi-Fi connection

**Blynk Console:** https://blynk.cloud/

## 🔄 Working Principle

1. The DHT11 measures temperature and humidity.
2. The MQ-2 sensor provides an analog gas-sensor reading.
3. The LDR module provides an analog light-sensor reading.
4. The Arduino UNO reads the sensor values.
5. The Arduino sends the readings to the ESP8266 using SoftwareSerial.
6. The ESP8266 connects to Wi-Fi.
7. The ESP8266 uploads the sensor values to Blynk.
8. The user views the sensor readings in the Blynk mobile app.

### Block Diagram

```text
       DHT11 Sensor
            |
       MQ-2 Sensor
            |
       LDR Sensor
            |
            v
       Arduino UNO
            |
     SoftwareSerial
            |
            v
      ESP8266 NodeMCU
            |
           Wi-Fi
            |
            v
        Blynk Cloud
            |
            v
      Blynk Mobile App
```

## 🔌 Circuit Connections

### 1. Sensors to Arduino UNO

| Component  | Pin  | Arduino UNO                    |
| ---------- | ---- | ------------------------------ |
| DHT11      | DATA | D4                             |
| DHT11      | VCC  | 5V, if supported by the module |
| DHT11      | GND  | GND                            |
| MQ-2       | AO   | A0                             |
| MQ-2       | VCC  | 5V, as required by the module  |
| MQ-2       | GND  | GND                            |
| LDR module | AO   | A1                             |
| LDR module | VCC  | 5V, if supported by the module |
| LDR module | GND  | GND                            |

### 2. Arduino UNO to ESP8266 NodeMCU

| Arduino UNO | ESP8266 NodeMCU  | Function             |
| ----------- | ---------------- | -------------------- |
| D9 (TX)     | D6 / GPIO12 (RX) | Sends sensor data    |
| D8 (RX)     | D5 / GPIO14 (TX) | Receives serial data |
| GND         | GND              | Common ground        |

**Important:** Connect Arduino UNO D9 TX to NodeMCU D6 RX through a voltage divider to reduce the UNO's 5V logic signal to approximately 3.3V. Never apply 5V directly to an ESP8266 GPIO pin.

The NodeMCU D5 TX pin can connect to Arduino UNO D8 RX.

## 📱 Blynk Virtual Pins

Create the following datastreams in your Blynk template.

| Virtual Pin | Sensor           | Data Type |
| ----------- | ---------------- | --------- |
| V0          | Temperature      | Double    |
| V1          | Humidity         | Double    |
| V2          | MQ-2 Gas Reading | Integer   |
| V3          | LDR Reading      | Integer   |

Add Gauge or Value Display widgets to your Blynk dashboard and assign them to the corresponding virtual pins.

## 📊 Example Output

Example serial data sent from Arduino UNO to NodeMCU:

```text
28,65,420,750
```

The values represent:

* Temperature: 28 °C
* Humidity: 65%
* MQ-2 analog reading: 420
* LDR analog reading: 750

The MQ-2 and LDR readings are raw analog values. They are not calibrated gas concentrations in ppm or light intensity in lux.

## 🚀 Setup Instructions

1. Install the Arduino IDE.
2. Install the ESP8266 board package.
3. Install the required DHT11 and Blynk libraries.
4. Create a Blynk account and a template for the ESP8266.
5. Create the four virtual-pin datastreams.
6. Copy the Blynk Template ID, Template Name, and Auth Token.
7. Upload the Arduino UNO program to the Arduino UNO.
8. Upload the NodeMCU program to the ESP8266.
9. Connect the boards according to the wiring table.
10. Enter your Wi-Fi credentials in the NodeMCU program.
11. Open the Blynk app and monitor the sensor readings.

## 🔐 Security Note

Before uploading this project to a public GitHub repository:

* Replace actual Blynk credentials with placeholders.
* Do not publish your Wi-Fi password.
* Do not publish your Blynk Auth Token.
* Enter your private credentials locally before uploading the code to your board.

If you have already published your credentials, change or revoke them.

## 🔧 Applications

* IoT-based environmental monitoring
* Basic gas-sensor monitoring
* Indoor light monitoring
* Electronics learning and experimentation
* Wireless sensor data monitoring

## 🔮 Future Improvements

* Add notifications for gas-sensor threshold values.
* Display sensor history using Blynk charts.
* Improve sensor calibration.
* Add additional sensors.
* Develop an automatic alert system.

## 👩‍💻 Technologies Used

* Arduino UNO
* ESP8266 NodeMCU
* Embedded C/C++
* SoftwareSerial communication
* Wi-Fi communication
* Blynk IoT platform

<img width="581" height="319" alt="image" src="https://github.com/user-attachments/assets/03484b9d-fc5f-4c67-8bd3-bec4ffdce380" />

