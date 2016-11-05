#include "IlluminateTask.h"
#include "Arduino.h"

IlluminateTask::IlluminateTask(int pin){
	this.pin = pin;
}

void DetectMotionTask::init(int period){
	Task::init(period);
	led = new Led(this.pin);    
}

void DetectMotionTask::tick(){
	if (Global.getPresence()){
		led->switchOn();
	} else {
		prev = current;
		current = millis();
		//Todo
	}
}
