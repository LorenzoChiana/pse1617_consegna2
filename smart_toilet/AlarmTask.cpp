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
	this->errorCounter = 0;
	this->counterThreshold = 200/period;
	currentTime = initialTime = millis();	
}

void AlarmTask::tick(){
	/*
	Serial.print("Input: ");
	Serial.print(Global->getAlarmInput());
	Serial.print("  Stop: ");
	Serial.print(Global->getAlarmStop());
	Serial.print("  Alarm: ");
	Serial.println(Global->getAlarm());
	*/
	//Verificare
	if (!Global->getAlarm() && firstAlarm){
		checkMovement();
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
		Serial.print("Still time: ");
		Serial.println(currentTime-initialTime);
		prevDistance = currentDistance;	
		currentDistance = Global->getDistance();
		bool isChanged = (fabs(currentDistance - prevDistance) > differenceThreshold);
		//Serial.println(fabs(currentDistance - prevDistance));
		if (isChanged) {
			this->errorCounter++;
			if (this->errorCounter>=2){
				initialTime = millis();
				Serial.println("Si e mosso");
				errorCounter = 0;
			}		
		} else {
			currentTime = millis();
			if ((currentTime-initialTime)>TMAX){
				Global->setAlarm(true);
				initialTime = currentTime = millis();
				Serial.println("Fermo da troppo");
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
		Serial.println("Allarme vero");
	}
}

void AlarmTask::checkAlarmStop(){
	if (Global->getAlarmStop()){
		Global->setAlarm(false);
		this->firstAlarm = true;
		Serial.println("Allarme stop");
	}
}