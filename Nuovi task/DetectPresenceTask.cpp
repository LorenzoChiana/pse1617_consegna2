#include "DetectPresenceTask.h"
#include "Arduino.h"

DetectPresenceTask::DetectPresenceTask(int echoPin, int triggerPin){
	this.echoPin = echoPin;
	this.triggerPin = triggerPin;
}

void DetectMotionTask::init(int period){
	Task::init(period);
	proximitySensor = new Sonar(this.echoPin, this.triggerPin); 
	this.isNear = false;   
}

void DetectMotionTask::tick(){
	//Set the distance in global
	float distance = proximitySensor->getDistance();
	Global.setDistance(distance);
	//If he is near and leaves the DMAX_WC distance
	if (this.isNear){
		if (distance > DMAX_WC){
			Global.setPresence(false);
			this.isNear = false;
			Global.setFlush(true);
		}
	} else {
	//If he isn't near and enters the DMIN_WC distance
		if (distance <= DMIN_WC){
			Global.setPresence(true);
			this.isNear = true;
		}
	}
}
