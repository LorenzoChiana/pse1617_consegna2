#ifndef __LEDCLEANINGTASK__
#define __LEDCLEANINGTASK__

#include "../Task.h"
#include "../components/Led.h"

class LedCleaningTask: public Task {
	int pin;
	Led* led;
	
public:
	LedCleaningTask(int pin);  
	void init(int period);  
	void tick();
};

#endif
