/*
 *  This header file stores symbols that concerns 
 *  the configuration of the system.
 *
 */
#ifndef __CONFIG__
#define __CONFIG__

#define T1_PIN 2
#define T2_PIN 3
#define L1_PIN 4
#define L2_PIN 5
#define L3_PIN 6
#define ECHO_PIN 7
#define TRIG_PIN 8
#define PIR_PIN 9

#define DMIN_WC 0.5
#define DMAX_WC 1

#define INTENSITY 5

#define TMAX 20000

#define COMMAND_USERS "user"
#define COMMAND_STATE "state"

#include "AlarmTask.h"
#include "GlobalState.h"
#include "CleaningTask.h"
#include "DetectMotionTask.h"
#include "DetectPresenceTask.h"
#include "FadeTask.h"
#include "IlluminateTask.h"
#include "LedCleaningTask.h"
#include "MsgTask.h"
#include "Scheduler.h"

#endif

