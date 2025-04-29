#include "AD8232.h"

int getECG() {
  return analogRead(ECG_PIN);
}

bool initializeAD8232() {
  pinMode(ECG_PIN, INPUT);
  return true;
}
