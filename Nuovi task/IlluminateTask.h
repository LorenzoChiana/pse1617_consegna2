#ifndef __ILLUMINATETASK__
#define __ILLUMINATETASK__

#include "Task.h"
#include "Led.h"

class IlluminateTask: public Task {
	int pin;
	Led* led;
	long current, prev;
public:

	IlluminateTask(int pin);  
	void init(int period);  
	void tick();
};

#endif
