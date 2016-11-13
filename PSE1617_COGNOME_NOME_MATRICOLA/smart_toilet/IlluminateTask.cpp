#include "IlluminateTask.h"
#include "Arduino.h"
#include "config.h"

IlluminateTask::IlluminateTask(int pin, GlobalState* Global){
	this->pin = pin;
	this->Global = Global;
}

void IlluminateTask::init(int period){
	Task::init(period);
	led = new Led(this->pin); 

	currentTime = initialTime = 0;
	currentState = prevState = 0;
}

void IlluminateTask::tick(){
	
	bool isTurendOff = (currentState == false && prevState == true);
	/*if (isTurendOff){
		currentTime = initialTime = millis();
	}*/
	if (Global->getPresence()){
		led->switchOn();

		prevState = currentState;
		currentState = true;
		// inizio a contare da quando me ne vado
		initialTime = millis();
	} else {
		currentTime = millis();
		if ((currentTime - initialTime >= TMAX_ILLUMINATE) && !isTurendOff){
			led->switchOff();			
		}
		prevState = currentState;
		currentState = false;
	}
	
}

