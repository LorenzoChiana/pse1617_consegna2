#ifndef __CLEANINGTASK__
#define __CLEANINGTASK__

#include "Task.h"

class CleaningTask: public Task {	
	char* getUsers();
	char* getState();
public:
	CleaningTask();  
	void init(int period);  
	void tick();
};

#endif