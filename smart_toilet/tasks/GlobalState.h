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

  int nUses;
  char writingBuffer[];
  bool bufferAvalible;
  
public:

  GlobalState();  
  void init();
  
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

  int getUsers();
  void incUsers();
  void resetUsers();

};

#endif
