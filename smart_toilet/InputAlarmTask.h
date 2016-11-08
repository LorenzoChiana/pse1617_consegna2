#ifndef __INPUTALARMTASK__
#define __INPUTALARMTASK__

#include "Task.h"
#include "Button.h"
#include "GlobalState.h"

class InputAlarmTask: public Task {
  int pin;
  Button* button;
  GlobalState *Global;
  bool currentState, prevState;
  long initialTime, prevTime;
public:
  InputAlarmTask(int pin, GlobalState *Global);  
  void init(int period);  
  void tick();
};

#endif
