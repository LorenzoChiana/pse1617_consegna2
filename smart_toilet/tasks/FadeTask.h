#ifndef __FADETASK__
#define __FADETASK__

#include "../Task.h"
#include "../components/LedExt.h"

class FadeTask: public Task {
	int pin, intensity, brightness, fadeAmount;
	Led* led;

	//counting 5 seconds
	long currentTime, initialTime;
	//counting 0,25 seconds
	long prevTime;

	bool currentState, prevState, fade;
public:

	FadeTask(int pin, int intensity);  
	void init(int period);  
	void tick();
};

#endif
