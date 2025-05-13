# Real-time Vital Signs Monitoring Project with ESP32 - Cancelled

## Project Overview

This project aimed to develop a **real-time vital signs monitoring system** using the **ESP32** microcontroller. The goal was to create a wearable device capable of monitoring various physiological parameters, such as **heart rate**, **blood oxygen saturation (SpO2)**, **body temperature**, and **respiratory rate**. The system was designed to send alerts in case any vital signs deviated from predefined thresholds, providing real-time health insights for individuals and healthcare professionals.

### Key Features:

* Real-time monitoring of **Heart Rate**, **SpO2**, **Temperature**, and **Respiratory Rate**.
* Wireless communication via **Wi-Fi** or **Bluetooth**, allowing data transfer to a cloud-based server or directly to a smartphone application.
* Alerts and notifications sent in case of abnormal readings.
* Data logging and historical analysis for long-term health monitoring.

## Technologies Used

### 1. **ESP32 Microcontroller**

The **ESP32** is a powerful, low-cost microcontroller that integrates both Wi-Fi and Bluetooth connectivity. Its processing capabilities, combined with various I/O options, make it an ideal choice for building connected health-monitoring systems.

* **Advantages**:

  * **Dual-core processor** for efficient handling of multiple tasks.
  * **Low power consumption**, making it suitable for wearable devices.
  * **Built-in Wi-Fi and Bluetooth** for easy communication with other devices or cloud systems.
  * **Integrated peripherals** for connecting various sensors.

### 2. **ESP-IDF (Espressif IoT Development Framework)**

**ESP-IDF** is the official development framework for the ESP32. It offers rich libraries, tools, and APIs to develop embedded applications efficiently.

* **Advantages**:

  * **Rich functionality** with support for various communication protocols, sensors, and peripherals.
  * **Optimized for ESP32**, ensuring maximum performance and resource management.
  * **Extensive documentation** and community support for troubleshooting and optimization.

### 3. **Sensors for Vital Signs Measurement**

Several sensors were planned for integration into the system:

* **MAX30102**: A sensor for **heart rate** and **SpO2** monitoring. This sensor combines both photodetectors and infrared LEDs, which is ideal for measuring oxygen levels in the blood and heart rate.
* **MLX90614**: An infrared temperature sensor for non-contact body temperature measurement.
* **DHT11/DHT22**: Humidity and temperature sensors for environmental monitoring, which can complement health data in some cases.
* **AD8232**: A sensor for **ECG (electrocardiogram)** monitoring, providing insights into heart activity.

### 4. **Cloud Integration & Mobile Application**

The project intended to use **cloud platforms** (such as **AWS IoT**, **Google Cloud**, or **ThingSpeak**) for storing and analyzing data, enabling real-time monitoring and long-term tracking. Alerts would be sent via a **mobile app** using **push notifications** or **SMS**.

### 5. **Alert System**

Based on predefined thresholds for each vital sign, the system would automatically send **alerts** to users or healthcare providers in case of abnormal readings, ensuring early intervention for potential health risks.

## Why the Project Was Cancelled

Due to various time constraints, the project was ultimately cancelled. However, the intended system design could still be implemented in the future. The key challenges faced were:

* **Development Time**: The complexity of integrating multiple sensors and ensuring real-time performance required more time than initially estimated.
* **Hardware Constraints**: Issues in selecting and calibrating the right sensors for the required precision.
* **Wireless Connectivity**: Achieving stable communication between the device and the cloud/mobile app proved more difficult than expected, especially in real-time data transmission.

Despite these challenges, the chosen technologies remain highly promising for similar future projects.

