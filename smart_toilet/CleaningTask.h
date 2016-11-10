#ifndef __CLEANINGTASK__
#define __CLEANINGTASK__

#include "Task.h"
#include "GlobalState.h"

class CleaningTask: public Task {	

	long currentTime, initialTime;
	bool executeCleaning, firstTime, userEntered;
	const char* message;
	GlobalState *Global;
public:
	CleaningTask(GlobalState *Global);  
	void init(int period);  
	void tick();
};

#endif
