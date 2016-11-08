#include "DetectMotionTask.h"
#include "Arduino.h"

AlarmLedTask::AlarmLedTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void DetectMotionTask::init(int period){
  Task::init(period);
  led = new Led(pin);    
}
  
void AlarmLedTask::tick(){
  if (Global->getAlarm()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
}
