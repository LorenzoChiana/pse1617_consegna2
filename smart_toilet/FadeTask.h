#ifndef __FADETASK__
#define __FADETASK__

#include "Task.h"
#include "LedExt.h"
#include "GlobalState.h"

class FadeTask: public Task {
	int pin, intensity, brightness, fadeAmount;
	LedExt* led;

	//counting 5 seconds
	long currentTime, initialTime;
	//counting 0,25 seconds
	long prevTime;

	bool currentState, prevState, fade;
	GlobalState* Global;
public:

	FadeTask(int pin, int intensity, GlobalState* Global);  
	void init(int period);  
	void tick();
};

#endif
