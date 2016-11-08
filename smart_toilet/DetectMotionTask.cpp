#include "DetectMotionTask.h"
#include "Arduino.h"

DetectMotionTask::DetectMotionTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}
  
void DetectMotionTask::init(int period){
  Task::init(period);
  pir = new PIRSensor(pin);    
}
  
void DetectMotionTask::tick(){
	/*Serial.print("pir: ");
	Serial.println(pir->detected());*/
  if (pir->detected()) {
    Global->setMotion(true);
  } else {
    Global->setMotion(false);
  }
}
