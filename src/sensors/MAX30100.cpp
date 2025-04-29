#include "MAX30100.h"
#include <Wire.h>
#include <MAX30100_PulseOximeter.h>

PulseOximeter pox;

bool initializeMAX30100() {
  if (pox.begin()) {
    pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
    return true;
  }
  return false;
}

float getHeartRate() {
  return pox.getHeartRate();
}

float getSpO2() {
  return pox.getSpO2();
}

bool isMAX30100Available() {
  return pox.begin();
}
