#ifndef __STOPALARMTASK__
#define __STOPALARMTASK__

#include "Task.h"
#include "Button.h"
#include "GlobalState.h"

class StopAlarmTask: public Task {
  int pin;
  Button* button;
  GlobalState *Global;

public:

  StopAlarmTask(int pin, GlobalState *Global);  
  void init(int period);  
  void tick();
};

#endif
