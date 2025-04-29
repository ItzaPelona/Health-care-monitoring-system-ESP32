#include "DS18B20.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

bool initializeDS18B20() {
  sensors.begin();
  sensors.requestTemperatures();
  return (sensors.getTempCByIndex(0) != DEVICE_DISCONNECTED_C);
}

float getBodyTemperature() {
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}
