#ifndef __GLOBALSTATE__
#define __GLOBALSTATE__

class GlobalState {
	bool pirState;
	bool prossimityState;
	bool flush;
	float distance;
	bool alarmState;
	bool cleaningState; 
public:

  GlobalState();  
  void init();
  
  void setMotion(bool value);
  void setProssimity(bool value); 
  void setAlarm(bool value);
  void setCleaning(bool value);
  void setFlush(bool value);
  bool getPresence();
  

};

#endif
