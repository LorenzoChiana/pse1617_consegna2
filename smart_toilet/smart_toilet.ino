#include "Led.h"
#include "LedExt.h"
#include "MotionDetector.h"
#include "PIRSensor.h"
#include "ProximitySensor.h"
#include "Sonar.h"

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
