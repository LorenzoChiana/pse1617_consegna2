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
	Global = new GlobalState();
	Global->init(period);
}

void AlarmTask::tick(){
	if (!Global->getAlarm()){
		checkMovement();
		checkAlarmInput();
	} else {
		if (this->firstAlarm){
			Global->setWritingBuffer("Allarmee!");
			this->firstAlarm = false;
		}
		checkAlarmStop();
	}	
}

void AlarmTask::checkMovement(){
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
		Global->setAlarm(true);
	}
}

void AlarmTask::checkAlarmStop(){
	if (Global->getAlarmStop()){
		Global->setAlarm(false);
		this->firstAlarm = true;
	}
}
