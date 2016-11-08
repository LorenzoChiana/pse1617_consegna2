#ifndef __ILLUMINATETASK__
#define __ILLUMINATETASK__

#include "Task.h"
#include "Led.h"
#include "GlobalState.h"

class IlluminateTask: public Task {
	int pin;
	Led* led;

	long currentTime, initialTime;
	bool currentState, prevState;

	GlobalState *Global;

public:
	IlluminateTask(int pin, GlobalState* Global);  
	void init(int period);  
	void tick();
};

#endif
