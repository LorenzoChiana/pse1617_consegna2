#ifndef __ALARMLEDTASK__
#define __ALARMLEDTASK__

#include "Task.h"
#include "Led.h"
#include "GlobalState.h"

class AlarmLedTask: public Task {
  int pin;
  Led* pir;
  GlobalState *Global;

public:

  AlarmLedTask(int pin, GlobalState *Global);  
  void init(int period);  
  void tick();
};

#endif
