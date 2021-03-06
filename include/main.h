
#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif
Gyro gyro;
extern int leftime, rightime;
#include "CodeSetUp.h"

#include "GeneralFunctions.h"

#include "DebugLCD.h"

#include "PID.h"

#include "MiscFunctions.h"

#include "KonamiCode.h"

#include "DebugHub.h"

#include "ImportantFunctions.h"

#include "AutoStack.h"

#include "TaskStaging.h"

extern int auton;

void autonselect();

void distanceDrivePID(int Desired, int distance);

void autonomous();

void initializeIO();

void initialize();

void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
