#include "AlarmTask.h"
#include "Arduino.h"
#include "math.h"
#include "config.h"

AlarmTask::AlarmTask(float differenceThreshold, GlobalState *Global){
	this->differenceThreshold = differenceThreshold;
	this->Global = Global;
}

void AlarmTask::init(int period){
	Task::init(period);
	this->firstAlarm = true;
	this->counterThreshold = 200/period;	
}

void AlarmTask::tick(){

	Serial.print("Input: ");
	Serial.print(Global->getAlarmInput());
	Serial.print("  Stop: ");
	Serial.println(Global->getAlarmStop());
	//Verificare
	if (!Global->getAlarm() && firstAlarm){
		//checkMovement();
		checkAlarmInput();
	} else {
		if (this->firstAlarm){
			Global->setWritingBuffer("Allarme!");	
			Serial.println(Global->getWritingBuffer());		
			this->firstAlarm = false;
		}
		checkAlarmStop();

	}	
}

void AlarmTask::checkMovement(){
	//Da verificare
	if (checkCounter == counterThreshold) {
		prevDistance = currentDistance;	
		currentDistance = Global->getDistance();
		bool isChanged = (fabs(currentDistance - prevDistance) > differenceThreshold);
		//Serial.println(fabs(currentDistance - prevDistance));
		if (isChanged) {
			this->errorCounter++;
			if (this->errorCounter>2){
				initialTime = millis();
				errorCounter = 0;
			}		
		} else {
			currentTime = millis();
			if ((currentTime-initialTime)>TMAX){
				Global->setAlarm(true);
			}
		}
		checkCounter = 0;
	} else {
		checkCounter++;	
	}
}

void AlarmTask::checkAlarmInput(){
	if (Global->getAlarmInput()){
		Global->setAlarm(true);
	}
}

void AlarmTask::checkAlarmStop(){
	if (Global->getAlarmStop()){
		Global->setAlarm(false);
		this->firstAlarm = true;
	}
}