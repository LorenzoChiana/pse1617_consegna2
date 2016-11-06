#ifndef __MSGTASK__
#define __MSGTASK__

#include "Task.h"

class MsgTask: public Task {	
	char* getUsers();
	char* getState();
public:
	MsgTask(float differenceThreshold);  
	void init(int period);  
	void tick();

};

#endif