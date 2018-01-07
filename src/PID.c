#include "main.h"

float PIDDebug[5][3] = {
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0},
  {0,0,0}};

int PIDDesired[5] = {0,0,0,0,0};

int primaryLastVal = 0;
void primaryLiftPID(int desired)
{
  int currentVal = analogRead(liftSetUp.primaryLeft);
  int error = desired - currentVal;
  int derivitive = currentVal - primaryLastVal;
  int output = PIDDebug[0][0] * error + PIDDebug[0][2] * derivitive;
  lift(output);
  primaryLastVal = currentVal;
}

int secondaryLastVal = 0;
void secondaryLiftPID(int desired)
{
  int currentVal = analogRead(liftSetUp.secondaryLeft);
  int error = desired - currentVal;
  int derivitive = currentVal - secondaryLastVal;
  int output = PIDDebug[1][0] * error + PIDDebug[1][2] * derivitive;
  secondaryLift(output);
  secondaryLastVal = currentVal;
}
