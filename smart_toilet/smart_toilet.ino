#include "tasks/AlarmTask.h"
#include "tasks/GlobalState.h"
#include "tasks/CleaningTask.h"
#include "tasks/DetectMotionTask.h"
#include "tasks/DetectPresenceTask.h"
#include "tasks/FadeTask.h"
#include "tasks/IlluminateTask.h"
#include "tasks/LedCleaningTask.h"
#include "tasks/MsgTask.h"
#include "config.h"
#include "Scheduler.h"

Scheduler sched;

void setup() {
  float f = 0.3;
  sched.init(20);
  Task* alarmTask = new AlarmTask(f);
  alarmTask->init(20);
  sched.addTask(alarmTask);

}

void loop() {
}
