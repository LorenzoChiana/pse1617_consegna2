#include "Arduino.h"
#include "config.h"
#include "blink.h"

void blinky(Light* led, int speedy) {
  led->switchOn();
  delay(speedy);
  led->switchOff(); 
  delay(speedy);
}

