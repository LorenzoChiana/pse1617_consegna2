#ifndef __CLEANINGTASK__
#define __CLEANINGTASK__

#include "../Task.h"

class CleaningTask: public Task {	

	long currentTime, initialTime;
	//bool currentState, prevState;
	bool executeCleaning, firstTime, userEntered;
public:
	CleaningTask();  
	void init(int period);  
	void tick();
};

#endif