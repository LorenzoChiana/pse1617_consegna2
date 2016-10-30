#include "LedExt.h"

#define T1_PIN 2
#define T2_PIN 3
#define L1_PIN 4
#define L2_PIN 5
#define L3_PIN 6
#define ECHO_PIN 7
#define TRIG_PIN 8
#define PIR_PIN 9

int brightness;
int fadeAmount;
LightExt* led2;

void setup() {
  //inizializzazione sciacquone
  brightness = 0;
  fadeAmount = 5;
  led2 = new LedExt(L2_PIN,brightness);
}

void loop() {
}
