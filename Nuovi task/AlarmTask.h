#ifndef __ALARMTASK__
#define __ALARMTASK__

#include "Task.h"
#include "Led.h"

class AlarmTask: public Task {
	int pin;
	Led* led;	
public:
	AlarmTask(int pin);  
	void init(int period);  
	void tick();
};

#endif
