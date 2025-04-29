#ifndef MAX30100_H
#define MAX30100_H

#include <MAX30100_PulseOximeter.h>
extern PulseOximeter pox;

bool initializeMAX30100();
float getHeartRate();
float getSpO2();
bool isMAX30100Available();

#endif