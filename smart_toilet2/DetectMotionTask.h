#ifndef __DETECTMOTIONTASK__
#define __DETECTMOTIONTASK__

#include "Task.h"
#include "PIRSensor.h"

class DetectMotionTask: public Task {
  int pin;
  PIRSensor* pir;

public:

  DetectMotionTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
