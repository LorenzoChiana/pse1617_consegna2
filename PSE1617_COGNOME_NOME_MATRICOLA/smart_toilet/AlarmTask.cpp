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
  //Se non c'è l'allarme controlla che non si sia mosso 
  if (!Global->getAlarm() && firstAlarm) {
    checkMovement();
    checkAlarmInput();
  } else {
    //Se è il primo allarme manda un messaggio
    if (this->firstAlarm) {
      this->firstAlarm = false;
      Global->setWritingBuffer(this->message);
    }
    //Controlla l'input di stop
    checkAlarmStop();

  }
}

void AlarmTask::checkMovement() {
  if (checkCounter == counterThreshold) {
    prevDistance = currentDistance;
    currentDistance = Global->getDistance();
    float difference = fabs(currentDistance - prevDistance);
    bool isChanged = (difference > differenceThreshold && difference < CORRECTION_BOUNCE);
    //Resetta il cronometro dei moviementi quando rileva presenza e si è mosso
    if (isChanged || !Global->getPresence() || reset) {
      initialTime = millis();
      reset = false;
    } else {
      currentTime = millis();
      if ((currentTime - initialTime) > TMAX) {
        Global->setAlarm(true);

        Global->setWritingBuffer(this->message);
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
