#ifndef __GLOBALSTATE__
#define __GLOBALSTATE__

class GlobalState {
	bool pirState;
	bool prossimityState;	
	
	bool cleaningState;
  bool alarmState;

  float distance;
  bool flush;

  bool alarmInput;
  bool alarmStop; 

  int nUsers;
  int period;
  char writingBuffer[100];
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
  bool isCleaning();
  int getUsers();
  void incUsers();
  void resetUsers();
  void setDistance(float distance);

  void setWritingBuffer(char* s);
  char* getWritingBuffer();
};

#endif
