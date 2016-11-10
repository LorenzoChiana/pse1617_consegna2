#include "FadeTask.h"
#include "Arduino.h"

FadeTask::FadeTask(int pin, int intensity, GlobalState* Global){
	this->pin = pin;
	this->intensity = intensity;
  this->Global = Global;
}

void FadeTask::init(int period){
	Task::init(period);
	led = new LedExt(this->pin, this->intensity);    

	currentTime = initialTime = 0;
	currentState = prevState = false;

	brightness = 0;
 	fadeAmount = 255/(125/period);
 	fade = true;
}

void FadeTask::tick(){
	if (Global->getFlush() && !Global->isCleaning()){
		led->switchOn();
		currentTime = millis();
		// 4 pulsazioni al secondo		
			//fading			
	  		brightness = brightness + fadeAmount;
	  		if (brightness<0){
	  			brightness = 0;
	  		}
	  		if (brightness>255){
	  			brightness=255;
	  		}
	  		if (brightness <= 0 || brightness >= 255) {
	    		fadeAmount = -fadeAmount ;
	  		} 
	  		led->setIntensity(brightness);
		// dopo 5 secondi smette lo sciacquone
		if (currentTime - initialTime > 5000){
			led->switchOff();	
			Global->setFlush(false);	
		}
	} else {
		currentTime = initialTime = millis();
		if (Global->isCleaning()){
				led->switchOff();
				Global->setFlush(false);
		}
	}
}
