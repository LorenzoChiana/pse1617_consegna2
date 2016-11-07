#include "FadeTask.h"
#include "Arduino.h"

FadeTask::FadeTask(int pin, int intensity){
	this->pin = pin;
	this->intensity = intensity;
}

void FadeTask::init(int period){
	Task::init(period);
	led = new Led(this->pin, this->intensity);    

	currentTime = initialTime = 0;
	currentState = prevState = false;

	brightness = 0;
 	fadeAmount = 5;
 	fade = true;
}

void FadeTask::tick(){
	
	bool isTurendOff = (currentState == false && prevState == true);
	if (isTurendOff){
		currentTime = initialTime = prevTime = millis();
	}

	if (Global.getFlush()){
		led->switchOn();

		prevState = currentState;
		currentState = true;

		currentTime = millis();
		// 4 pulsazioni al secondo
		if(currentTime - prevTime < 250 && fade){
			//fading
			led->setIntensity(brightness);
	  		brightness = brightness + fadeAmount;

	  		if (brightness == 0 || brightness == 255) {
	    		fadeAmount = -fadeAmount ; 
	  		} 
	  		//per garantire che si accenda e si spenga solo una volta ogni 0,25 secondi
	  		if(brightness == 0) {
	  			fade = false;
	  		}
		} else {
			prevTime = millis();
			brightness = 0;
			fade = true;
	  	}

		// dopo 5 secondi smette lo sciacquone
		if (currentTime - initialTime > 5000){
			led->switchOff();	
			Global.setFlush(false);	
			prevState = currentState;
			currentState = false;	
		}
	}
}
