#include "GlobalState.h"
#include "Arduino.h"

GlobalState::GlobalState(int pin){
}
  
void GlobalState::init(int period){
}

void GlobalState::setMotion(bool value){
	this->pirState = value;
}

void GlobalState::setProssimity(bool value){
	this->prossimityState = value;
}
void GlobalState::setFlush(bool value){
	this->flush = value;
}

bool GlobalState::getFlush(){
	return this->flush;
}

void GlobalState::setAlarm(bool value){
	this->alarmState = value;
}
bool GlobalState::getAlarm(){
	return this->alarmState;
}

void GlobalState::setCleaning(bool value){
	this->cleaningState = value;
}

bool GlobalState::getPresence(){
	return (this->pirState || this->prossimityState);
}

float GlobalState::getDistance(){
	return this->distance;
}