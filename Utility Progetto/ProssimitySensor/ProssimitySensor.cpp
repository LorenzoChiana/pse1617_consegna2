#include "ProssimitySensor.h"
#include "Arduino.h"

ProssimitySensor::ProssimitySensor(int triggerPin, int echoPin){
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
float ProssimitySensor::getSoundSpeed(){
  return soundSpeed;
}
float ProssimitySensor::getDistance(){
  /* Sending the pulse */
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(3);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(3);
  digitalWrite(triggerPin,LOW);

  /* Receving the echo */
  long tUS = pulseIn(echoPin, HIGH);
  //Getting the value in seconds of the pulse duration
  long t = tUS / 1000.0 / 1000.0 / 2;
  float distance = t * getSoundSpeed();
  return distance;
}
bool ProssimitySensor::isDistant(float distanceThreshold){
  return (getDistance()>distanceThreshold);
}
