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
	
}

void AlarmTask::tick(){
	Serial.println(Global->getAlarm());

	if (!Global->getAlarm()){
		checkMovement();
		checkAlarmInput();
	} else {
		if (this->firstAlarm){
			Global->setWritingBuffer("Allarmee!");
			Serial.println("Primo Allarme");			
			this->firstAlarm = false;
		}
		checkAlarmStop();
	}	
}

void AlarmTask::checkMovement(){
	prevDistance = currentDistance;
	currentDistance = Global->getDistance();
	bool isChanged = (fabs(currentDistance - prevDistance) > differenceThreshold);
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
}

void AlarmTask::checkAlarmInput(){
	if (Global->getAlarmInput()){
		Serial.println("ALARM");
		Global->setAlarm(true);
	}
}

void AlarmTask::checkAlarmStop(){
	if (Global->getAlarmStop()){
		Serial.println("Stop");
		Global->setAlarm(false);
		this->firstAlarm = true;
	}
}
