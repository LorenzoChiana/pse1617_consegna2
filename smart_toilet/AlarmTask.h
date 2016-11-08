#ifndef __ALARMTASK__
#define __ALARMTASK__

#include "Task.h"
#include "GlobalState.h"

class AlarmTask: public Task {	
	float differenceThreshold;
	float currentDistance, prevDistance;
	long currentTime, initialTime;
	int errorCounter;

	bool firstAlarm;
	char alarmMsg[];

	GlobalState *Global;

	void checkMovement();
	void checkAlarmInput();
	void checkAlarmStop();
public:
	AlarmTask(float, GlobalState*);  
	void init(int);  
	void tick();

};

#endif
