#ifndef __GLOBALSTATE__
#define __GLOBALSTATE__

class GlobalState {
	bool pirState;
	bool prossimityState;	
	
	bool cleaningState;
  bool alarmState;

  float distance;
  bool flush; 
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

  void setFlush(bool value);
  bool getFlush();

};

#endif
