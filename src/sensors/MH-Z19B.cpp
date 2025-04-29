#include "MHZ19B.h"
#include <MHZ19.h>
#include <HardwareSerial.h>

MHZ19 mhz19;
HardwareSerial mySerial(2);

bool initializeMHZ19B() {
  mySerial.begin(9600, SERIAL_8N1, 16, 17);
  mhz19.begin(mySerial);
  delay(1000);
  int co2 = mhz19.getCO2();
  return (co2 > 0 && co2 < 5000);
}

int getCO2() {
  return mhz19.getCO2();
}
