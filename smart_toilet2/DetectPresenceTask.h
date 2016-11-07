#ifndef __DETECTPRESENCETASK__
#define __DETECTPRESENCETASK__

#include "Task.h"
#include "Sonar.h"

class DetectPresenceTask: public Task {
	int echoPin, triggerPin;
	bool isNear;

	Sonar* proximitySensor;
public:
	DetectPresenceTask(int echoPin, int triggerPin);  
	void init(int period);  
	void tick();
};

#endif
