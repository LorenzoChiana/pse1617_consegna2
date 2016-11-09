#include "ButtonImpl.h"
#include "Arduino.h"
#include "InputAlarmTask.h"

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
    if (currentTime-initialTime>2000){
    	Global->setAlarmInput(true);
    }
  } else {
    initialTime = millis();
    Global->setAlarmInput(false);
  }
}
