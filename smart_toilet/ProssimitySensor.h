#ifndef __PROSSIMITYSENSOR__
#define __PROSSIMITYSENSOR__

class ProssimitySensor {

public:
  ProssimitySensor(int triggerPin, int echoPin);
  float getDistance();
  bool isDistant(float distanceThreshold);

private:
  //Sound speed at 20 degrees
  const float soundSpeed = 331.5 +0.6*20;
  int triggerPin;
  int echoPin;
  float getSoundSpeed();
};

#endif
