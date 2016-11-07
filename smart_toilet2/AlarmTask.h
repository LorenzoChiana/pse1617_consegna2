#ifndef __ALARMTASK__
#define __ALARMTASK__

#include "Task.h"

class AlarmTask: public Task {	
	float differenceThreshold;
	float currentDistance, prevDistance;
	long currentTime, initialTime;
	int errorCounter;

	bool firstAlarm;
	char alarmMsg[];

	void checkMovement();
	void checkAlarmInput();
	void checkAlarmStop();
public:
	AlarmTask(float);  
	void init(int);  
	void tick();

};

#endif