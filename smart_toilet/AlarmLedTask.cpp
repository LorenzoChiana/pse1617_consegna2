#include "DetectMotionTask.h"
#include "Arduino.h"
#include "AlarmLedTask.h"

AlarmLedTask::AlarmLedTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void AlarmLedTask::init(int period){
  Task::init(period);
  led = new Led(this->pin);    
}
  
void AlarmLedTask::tick(){
  if (Global->getAlarm()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
}
