#include "ButtonImpl.h"
#include "Arduino.h"
#include "StopAlarmTask.h"

StopAlarmTask::StopAlarmTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void StopAlarmTask::init(int period){
  Task::init(period);
  button = new ButtonImpl(pin);    
}
  
void StopAlarmTask::tick(){
  //Serial.println(digitalRead(pin));
  if (button->isPressed()) {
    Global->setAlarmStop(true);
  } else {
    Global->setAlarmStop(false);
  }
}