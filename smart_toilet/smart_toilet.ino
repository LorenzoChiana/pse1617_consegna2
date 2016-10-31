#include "Led.h"
#include "LedExt.h"
#include "MotionDetector.h"
#include "PIRSensor.h"
#include "ProximitySensor.h"
#include "Sonar.h"
#include "config.h"
#include "blink.h"

int brightness;
int fadeAmount;

Light* led1;
Light* led3;
LightExt* led2;
MotionDetector* pir;
ProximitySensor* proxSensor;

void setup() {
  led1 = new Led(L1_PIN);
  
  //inizializzazione sciacquone
  brightness = 0;
  fadeAmount = 5;
  led2 = new LedExt(L2_PIN,brightness); 
  
  led3 = new Led(L3_PIN); 
  
  pir = new PIRSensor(PIR_PIN);
  
  proxSensor = new Sonar(ECHO_PIN, TRIG_PIN);
}

void loop() {
}
