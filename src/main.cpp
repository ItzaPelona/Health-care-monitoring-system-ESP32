#include <WiFi.h>
#include <Wire.h>
#include <HTTPClient.h>

#include "MAX30100.h"
#include "DS18B20.h"
#include "MH-Z19B.h"
#include "AD8232.h"

uint32_t tsLastReport = 0;

// WIFI CREDENTIALS
const char *ssid = "ESP32-Entry-Point"; //creates a ssid so its visible to other devices nearby
const char *password = "123456789"; //makes a password... lel

const char *serverURL = "127.0.0.1"; //localhost

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Initializing sensors...");
  
    // Initialize sensors
    if (initializeMAX30100()) {
        Serial.println("✔ MAX30100 initialized");
    } else {
        Serial.println("✖ MAX30100 NOT found");
    }
    // Initialize DS18B20
    if (initializeDS18B20()) {
        Serial.println("✔ DS18B20 initialized");
    } else {
        Serial.println("✖ DS18B20 NOT found");
    }
    // Initialize MH-Z19B
    if (initializeMHZ19B()) {
        Serial.println("✔ MH-Z19B initialized");
    } else {
        Serial.println("✖ MH-Z19B NOT found");
    }

    // Initialize AD8232
    if (initializeAD8232()) {
        Serial.println("✔ AD8232 initialized");
    } else {
        Serial.println("✖ AD8232 NOT found");
    }

    // Initialize WiFi
    WiFi.softAP(ssid, password);
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
}

void loop() {
    if (millis() - tsLastReport > 2000) {
        Serial.println("---- Sensor Readings ----");
    
        // MAX30100
        if (isMAX30100Available()) {
          float hr = getHeartRate();
          float spo2 = getSpO2();
          Serial.print("HR: "); Serial.print(hr); Serial.print(" bpm | SpO2: "); Serial.print(spo2); Serial.println(" %");
        } else {
          Serial.println("MAX30100 not available");
        }
    
        // DS18B20
        float temp = getBodyTemperature();
        if (temp != DEVICE_DISCONNECTED_C) {
          Serial.print("Body Temp: "); Serial.print(temp); Serial.println(" °C");
        } else {
          Serial.println("DS18B20 not available");
        }
    
        // MH-Z19B
        int co2 = getCO2();
        if (co2 > 300 && co2 < 5000) {
          Serial.print("CO2: "); Serial.print(co2); Serial.println(" ppm");
        } else {
          Serial.println("MH-Z19B reading out of range");
        }
    
        // AD8232
        int ecg = getECG();
        Serial.print("ECG Analog: "); Serial.println(ecg);
    
        Serial.println("--------------------------");
        tsLastReport = millis();
      }
}
