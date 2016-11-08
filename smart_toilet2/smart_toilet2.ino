#include "AlarmTask.h"
#include "GlobalState.h"
#include "CleaningTask.h"
#include "DetectMotionTask.h"
#include "DetectPresenceTask.h"
#include "FadeTask.h"
#include "IlluminateTask.h"
#include "LedCleaningTask.h"
#include "MsgTask.h"
#include "config.h"
#include "Scheduler.h"

Scheduler sched;
GlobalState *Global;

void setup() {
  Global = new GlobalState();
  sched.init(20);
  
  Task* alarmTask = new AlarmTask(0.3, Global);
  alarmTask->init(20);
  sched.addTask(alarmTask);

  Task* cleaningTask = new CleaningTask(Global);
  cleaningTask->init(20);
  sched.addTask(cleaningTask);

  Task* detectMotion = new DetectMotionTask(PIR_PIN,Global);
  detectMotion->init(20);
  sched.addTask(detectMotion);

}

void loop() {
}
