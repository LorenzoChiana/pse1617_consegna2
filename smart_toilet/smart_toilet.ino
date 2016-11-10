#include "config.h"

Scheduler sched;
GlobalState *Global;

void setup() {
  Serial.begin(9600);
  Global = new GlobalState();
  Global->init();
  sched.init(10);
  /*
    task che controlla se l'utente viene rilevato e resta per troppo tempo immobile
  */
  
  /*
    Auto pulizia del bagno
  */
  /*
  Task* cleaningTask = new CleaningTask(Global);
  cleaningTask->init(20);
  sched.addTask(cleaningTask);
  */
  /*
    L3 che segnala che sta avvenendo la pulizia nel bagno
  */
  /*
  Task* ledCleaningTask = new LedCleaningTask(L3_PIN, Global);
  ledCleaningTask->init(20);
  sched.addTask(ledCleaningTask);
  */
  /*
    PIR per la rilevazione della preenza della persona
  */
  
  Task* detectMotion = new DetectMotionTask(PIR_PIN,Global);
  detectMotion->init(20);
  sched.addTask(detectMotion);


  /*
    L2 che simula lo sciacquone
  */
  Task* fadeTask = new FadeTask(L2_PIN, INTENSITY, Global);
  fadeTask->init(20);
  sched.addTask(fadeTask);

  /*
    sencore ad ultra suoni che rileva la vicinanza al water dell'utente
  */
  
  Task* detectPresenceTask = new DetectPresenceTask(ECHO_PIN, TRIG_PIN,Global);
  detectPresenceTask->init(20);
  sched.addTask(detectPresenceTask);

  
  /*
    L1 che simula la luce
  */
  
  Task* illuminateTask = new IlluminateTask(L1_PIN, Global);
  illuminateTask->init(20);
  sched.addTask(illuminateTask);
  
  Task* alarmTask = new AlarmTask(STILL_DISTANCE_THRESHOLD, Global);
  alarmTask->init(20);
  sched.addTask(alarmTask);  

  Task* inputAlarmTask = new InputAlarmTask(T1_PIN,Global);
  inputAlarmTask->init(20);
  sched.addTask(inputAlarmTask);

  Task* stopAlarmTask = new StopAlarmTask(T2_PIN,Global);
  stopAlarmTask->init(20);
  sched.addTask(stopAlarmTask);

  Task* alarmLedTask = new AlarmLedTask(L3_PIN,Global);
  alarmLedTask->init(20);
  sched.addTask(alarmLedTask);

  Task* msgTask = new MsgTask(Global);
  msgTask->init(20);
  sched.addTask(msgTask);

}

void loop() {
  sched.schedule();
}
