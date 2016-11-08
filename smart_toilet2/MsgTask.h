#ifndef __MSGTASK__
#define __MSGTASK__

#include "Task.h"
#include "GlobalState.h"

class MsgTask: public Task {	
	char* getUsers();
	char* getState();
	GlobalState *Global;
public:
	MsgTask(/*float differenceThreshold,*/ GlobalState *Global);  
	void init(int period);  
	void tick();
};

#endif