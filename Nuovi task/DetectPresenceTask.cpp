#include "DetectPresenceTask.h"
#include "Arduino.h"

DetectPresenceTask::DetectPresenceTask(int echoPin, int triggerPin){
	this.echoPin = echoPin;
	this.triggerPin = triggerPin;
}

void DetectMotionTask::init(int period){
	Task::init(period);
	proximitySensor = new Sonar(this.echoPin, this.triggerPin);    
}

void DetectMotionTask::tick(){
	//Set the distance in global
	float distance = proximitySensor->getDistance();
	Global.setDistance(distance);
	//Set a flush variable to determinate if he is gone
	if (distance <= DMIN){
		Global.setPresence(true);
	}
	if (distance > DMAX){
		Global.setPresence(false);
		Global.setFlush(true);
	}
}
