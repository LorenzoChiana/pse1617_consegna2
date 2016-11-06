#ifndef __LEDCLEANINGTASK__
#define __LEDCLEANINGTASK__

#include "Task.h"
#include "Led.h"

class IlluminateTask: public Task {
	int pin;
	Led* led;
	
public:

	IlluminateTask(int pin);  
	void init(int period);  
	void tick();
};

#endif
