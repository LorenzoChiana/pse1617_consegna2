#include "DetectMotionTask.h"
#include "Arduino.h"

DetectMotionTask::DetectMotionTask(int pin){
  this->pin = pin;  
}
  
void DetectMotionTask::init(int period){
  Task::init(period);
  pir = new PIRSensor(pin);    
}
  
void DetectMotionTask::tick(){
  if (pir->detected()) {
    Global.setMotion(true);
  } else {
    Global.setMotion(false);
  }
}
