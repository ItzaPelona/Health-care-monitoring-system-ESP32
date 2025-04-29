#ifndef DS18B20_H
#define DS18B20_H

#include <DallasTemperature.h>

extern DallasTemperature sensors;
extern OneWire oneWire;

bool initializeDS18B20();
float getBodyTemperature();

#endif
