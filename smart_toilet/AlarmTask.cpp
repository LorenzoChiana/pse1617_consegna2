#include "AlarmTask.h"
#include "Arduino.h"
#include "math.h"
#include "config.h"

AlarmTask::AlarmTask(float differenceThreshold, GlobalState* Global) {
  this->differenceThreshold = differenceThreshold;
  this->Global = Global;
}

void AlarmTask::init(int period) {
  Task::init(period);
  this->firstAlarm = true;
  this->counterThreshold = 100 / period;
  this->reset = true;
  this->message = "WARNING: Alarm!";
}

void AlarmTask::tick() {
  if (!Global->getAlarm() && firstAlarm) {
    checkMovement();
    checkAlarmInput();
  } else {
    if (this->firstAlarm) {
      this->firstAlarm = false;
      Global->setWritingBuffer(this->message);
    }
    checkAlarmStop();

  }
}

void AlarmTask::checkMovement() {
  if (checkCounter == counterThreshold) {
    prevDistance = currentDistance;
    currentDistance = Global->getDistance();
    float difference = fabs(currentDistance - prevDistance);
    bool isChanged = (difference > differenceThreshold && difference < 5);
    if (isChanged || !Global->getPresence() || reset) {
      initialTime = millis();
      reset = false;
    } else {
      currentTime = millis();
      if ((currentTime - initialTime) > TMAX) {
        Global->setAlarm(true);
        this->firstAlarm = false;
        reset = true;
      }
    }
    checkCounter = 0;
  } else {
    checkCounter++;
  }
}

void AlarmTask::checkAlarmInput() {
  if (Global->getAlarmInput()) {
    Global->setAlarm(true);
    this->reset = true;
  }
}

void AlarmTask::checkAlarmStop() {
  if (Global->getAlarmStop()) {
    Global->setAlarm(false);
    this->firstAlarm = true;
    this->reset = true;
  }
}
