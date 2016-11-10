#include "ButtonImpl.h"
#include "Arduino.h"
#include "StopAlarmTask.h"

StopAlarmTask::StopAlarmTask(int pin, GlobalState *Global){
  this->pin = pin;  
  this->Global = Global;
}

void StopAlarmTask::init(int period){
  Task::init(period);
  button = new ButtonImpl(pin);    
}

void StopAlarmTask::tick(){
  //Serial.println(digitalRead(pin));
  if (button->isPressed()) {
        /*
    DUBBIO LOGICO: se l'allarme è stato attivato e poi disattivato 
    si presuppone che l'utente sia ancora in bagno o se sia già uscito?
    Nel caso l'allarme venga disattivato dopo che l'utente venga portato fuori
    allora qui è da inserire: 
    Global->incUsers();
    prima di Global->setAlarmStop(true); altrimenti va in conflitto con cleaningtask
    */
    Global->setAlarmStop(true);
  } else {
    Global->setAlarmStop(false);
  }
}