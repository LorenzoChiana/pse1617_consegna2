#ifndef __LEDCLEANINGTASK__
#define __LEDCLEANINGTASK__

#include "Task.h"
#include "Led.h"
#include "GlobalState.h"

class LedCleaningTask: public Task {
	int pin;
	Led* led;
	GlobalState *Global;
	
public:
	LedCleaningTask(int pin, GlobalState* Global);  
	void init(int period);  
	void tick();
};

#endif
