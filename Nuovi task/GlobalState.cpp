#include "GlobalState.h"
#include "Arduino.h"

GlobalState::GlobalState(int pin){
}
  
void GlobalState::init(int period){
}

void GlobalState::setMotion(bool value){
	this.pirState = value;
}

void GlobalState::setProssimity(bool value){
	this.prossimityState = value;
}
void GlobalState::setFlush(bool value){
	this.flush = value;
}

void GlobalState::setAlarm(bool value){
	this.alarmState = value;
}
bool getAlarm(){
	return this.alarmState;
}

void GlobalState::setCleaning(bool value){
	this.cleaningState = value;
}

bool GlobalState::getPresence(){
	return (pirState || prossimityState);
}

float getDistance(){
	return this.distance;
}


