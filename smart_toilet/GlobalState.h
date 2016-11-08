#ifndef __GLOBALSTATE__
#define __GLOBALSTATE__

class GlobalState {
	bool pirState;
	bool prossimityState;	
	
	bool cleaningState;
  bool alarmState;

  float distance;
  bool flush;

  int alarmInput;
  int alarmStop; 
  int nUsers;
  int period;
  char writingBuffer[];
  bool bufferAvalible;
public:

  GlobalState();  
  void init(int period);
  
  void setMotion(bool value);
  void setProssimity(bool value);

  bool getPresence();  
  float getDistance();

  void setCleaning(bool value);  

  void setAlarm(bool value);
  bool getAlarm();
  void setAlarmInput(bool value);
  bool getAlarmInput();
  void setAlarmStop(bool value);
  bool getAlarmStop();

  void setFlush(bool value);
  bool getFlush();
  bool isCleaning();
  int getUsers();
  void incUsers();
  void resetUsers();
  void setDistance(float distance);
};

#endif
