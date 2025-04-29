#ifndef MHZ19B_H
#define MHZ19B_H

#include <MHZ19.h>
#include <HardwareSerial.h>

extern MHZ19 mhz19;
extern HardwareSerial mySerial;

bool initializeMHZ19B();
int getCO2();

#endif
