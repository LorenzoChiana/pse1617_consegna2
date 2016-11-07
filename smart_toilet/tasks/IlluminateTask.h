#ifndef __ILLUMINATETASK__
#define __ILLUMINATETASK__

#include "../Task.h"
#include "../components/Led.h"

class IlluminateTask: public Task {
	int pin;
	Led* led;

	long currentTime, initialTime;
	bool currentState, prevState;

public:
	IlluminateTask(int pin);  
	void init(int period);  
	void tick();
};

#endif
