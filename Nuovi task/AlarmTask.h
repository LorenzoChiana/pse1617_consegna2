#ifndef __ALARMTASK__
#define __ALARMTASK__

#include "Task.h"
#include "Led.h"

class AlarmTask: public Task {	
public:
	AlarmTask();  
	void init(int period);  
	void tick();
};

#endif