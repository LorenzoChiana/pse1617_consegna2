#include "ButtonImpl.h"
#include "Arduino.h"
#include "InputAlarmTask.h"
#include "config.h"

InputAlarmTask::InputAlarmTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void InputAlarmTask::init(int period){
  Task::init(period);
  button = new ButtonImpl(pin);    
}
  
void InputAlarmTask::tick(){
  if (button->isPressed()) {
    currentTime = millis();
    if (currentTime-initialTime > TSTART_ALARM){
    	Global->setAlarmInput(true);
    }
  } else {
    initialTime = millis();
    Global->setAlarmInput(false);
  }
}
