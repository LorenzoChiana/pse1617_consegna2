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

void setup() {
  float f = 0.1;
  sched.init(20);
  Task* alarmTask = new AlarmTask(f);
  alarmTask->init(20);
  sched.addTask(alarmTask);

}

void loop() {
}
