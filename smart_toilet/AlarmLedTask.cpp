#include "DetectMotionTask.h"
#include "Arduino.h"
#include "AlarmLedTask.h"
#include "config.h"

AlarmLedTask::AlarmLedTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void AlarmLedTask::init(int period){
  Task::init(period);
  led = new Led(this->pin);  
  firstTime = true;  
}
  
void AlarmLedTask::tick(){
  if (Global->getAlarm()) {
    if(firstTime) {
      prevTime = millis();
      firstTime = false;
    }
    currentTime = millis();
    if(currentTime - prevTime < DELAY_LED) {
      led->switchOn();
    } else {
      led->switchOff();
      if(currentTime - prevTime >= DELAY_LED*2) {
        firstTime = true;
      }
    }
  } else {
  	if (!Global->isCleaning()){
    	led->switchOff();
  	}
  }
}
