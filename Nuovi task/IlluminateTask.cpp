#include "IlluminateTask.h"
#include "Arduino.h"

IlluminateTask::IlluminateTask(int pin){
	this->pin = pin;
}

void IlluminateTask::init(int period){
	Task::init(period);
	led = new Led(this->pin); 

	currentTime = initialTime = 0;
	currentState = prevState = 0;
}

void IlluminateTask::tick(){

	bool isTurendOff = (currentState == false && prevState == true);
	if (isTurendOff){
		currentTime = initialTime = millis();
	}

	if (Global.getPresence()){
		led->switchOn();

		prevState = currentState;
		currentState = true;
	} else {
		currentTime = millis();
		if (currentTime - initialTime > 10000){
			led->switchOff();			
		}
		prevState = currentState;
		currentState = false;
	}
	
}

