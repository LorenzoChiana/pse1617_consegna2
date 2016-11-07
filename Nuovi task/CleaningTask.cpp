#include "ClaeaningTask.h"
#include "Arduino.h"

ClaeaningTask::ClaeaningTask(int pin){
	this->pin = pin;
}

void ClaeaningTask::init(int period){
	Task::init(period);
	
	currentTime = initialTime = 0;
	currentState = prevState = 0;
	executeCleaning = false;

}

void ClaeaningTask::tick(){
	if (Global.getUsers()%10==0 && executeCleaning){
		Global.setCleaning(true);

		bool isTurendOff = (currentState == false && prevState == true);
		if (isTurendOff){
			currentTime = initialTime = millis();
		}
		if (Global.getPresence()){

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

}