#include "AlarmTask.h"
#include "Arduino.h"
#include "math.h"

AlarmTask::AlarmTask(float differenceThreshold){
	this->differenceThreshold = differenceThreshold;
}

void AlarmTask::init(int period){
	Task::init(period);
	this->firstAlarm = true;
}

void AlarmTask::tick(){
	if (!Global.getAlarm()){
		checkMovement();
		checkAlarmInput();
	} else {
		if (this->firstAlarm){
			Global.writeBuffer(this->alarmMsg); //TODO
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
			//Global.setAlarm(true);
		}
	}
}

void AlarmTask::checkAlarmInput(){
	if (Global.getAlarmInput()){
		Global.setAlarm(true);
	}
}

void AlarmTask::checkAlarmStop(){
	if (Global.getAlarmStop()){
		Global.setAlarm(false);
		this->firstAlarm = true;
	}
}
