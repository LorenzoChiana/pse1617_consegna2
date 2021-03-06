#include "GlobalState.h"
#include <string.h>
#include "Arduino.h"

GlobalState::GlobalState(){
}

void GlobalState::init(){
  

  this->setFlush(false);
  this->setAlarmInput(false);
  this->setAlarmStop(false);
  this->setAlarm(false);
  this->setAlarmInput(false);
  this->setCleaning(false);
  this->setWritingBuffer("");
  this->resetUsers();
}

void GlobalState::setMotion(bool value){
	this->pirState = value;
}

void GlobalState::setProssimity(bool value){
	this->prossimityState = value;
}

bool GlobalState::getPresence(){
	return (this->pirState || this->prossimityState);
}

float GlobalState::getDistance(){
	return this->distance;
}

void GlobalState::setDistance(float distance){
	this->distance = distance;
}

void GlobalState::setAlarm(bool value){
	this->alarmState = value;
}
bool GlobalState::getAlarm(){
	return this->alarmState;
}

void GlobalState::setAlarmInput(bool value){
	this->alarmInput=value;
}

bool GlobalState::getAlarmInput(){
	return this->alarmInput;
}

void GlobalState::setAlarmStop(bool value){
	this->alarmStop=value;
}

bool GlobalState::getAlarmStop(){
	return this->alarmStop;
}

void GlobalState::setCleaning(bool value){
	this->cleaningState = value;
}

bool GlobalState::isCleaning(){
	return this->cleaningState;
}

void GlobalState::setFlush(bool value){
	this->flush = value;
}

bool GlobalState::getFlush(){
	return this->flush;
}

int GlobalState::getUsers(){
	return this->nUsers;
}

void GlobalState::incUsers(){
	this->nUsers++;
}

void GlobalState::resetUsers(){
	this->nUsers=0;
}

void GlobalState::setWritingBuffer(char* s){
	if (this->bufferAvalible){
		noInterrupts();
		this->bufferAvalible = false;
		if (strlen(s)==0){
			strcpy(this->writingBuffer,s);
		} else {
			if (strlen(this->writingBuffer)>0){
				strcat(this->writingBuffer,"\n");
				strcat(this->writingBuffer,s);
			} else {
				strcpy(this->writingBuffer,s);
			}
		}
		this->bufferAvalible = true;
		interrupts();
	}
}

char* GlobalState::getWritingBuffer(){
	return this->writingBuffer;
}
