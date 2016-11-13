#ifndef __ALARMLEDTASK__
#define __ALARMLEDTASK__

#include "Task.h"
#include "Led.h"
#include "GlobalState.h"

class AlarmLedTask: public Task {
  int pin;
  Led* led;
  GlobalState *Global;
  int prevTime, currentTime;
  bool firstTime;
public:

  AlarmLedTask(int pin, GlobalState *Global);  
  void init(int period);  
  void tick();
};

#endif
