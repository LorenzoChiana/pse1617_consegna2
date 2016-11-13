#ifndef __DETECTMOTIONTASK__
#define __DETECTMOTIONTASK__

#include "Task.h"
#include "PIRSensor.h"
#include "GlobalState.h"

class DetectMotionTask: public Task {
  int pin;
  PIRSensor* pir;
  GlobalState *Global;

public:

  DetectMotionTask(int pin, GlobalState *Global);  
  void init(int period);  
  void tick();
};

#endif
