#include "LedCleaningTask.h"
#include "Arduino.h"

LedCleaningTask::LedCleaningTask(int pin, GlobalState* Global){
	this->pin = pin;
	this->Global = Global;
}

void LedCleaningTask::init(int period){
	Task::init(period);
	led = new Led(this->pin); 
}

void LedCleaningTask::tick(){

	if(Global->isCleaning()){
		led->switchOn();
	} else {
		led->switchOff();
	}
}

