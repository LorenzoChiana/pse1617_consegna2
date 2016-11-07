#include "LedCleaningTask.h"
#include "Arduino.h"

LedCleaningTask::LedCleaningTask(int pin){
	this->pin = pin;
}

void LedCleaningTask::init(int period){
	Task::init(period);
	led = new Led(this->pin); 
}

void LedCleaningTask::tick(){

	if(Global.isCleaning()){
		led->switchOn();
	} else {
		led->switchOff();
	}
}

