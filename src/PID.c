#include "main.h"

float PIDDebug[5][3] = {
  /*Primary Lift*/  {0,0,0},
  /*Secondary Lift*/{0,0,0},
  /*LeftDrive*/     {0,0,0},
  /*RightDrive*/    {0,0,0},
  /**/              {0,0,0}};

int PIDDesired[5] = {0,0,0,0,0};

int primaryLastVal = 0;
void primaryLiftPID(int desired)
{
  int currentVal = analogRead(liftSetUp.primaryLeft);
  float error = desired - currentVal;
  float derivitive = currentVal - primaryLastVal;
  float output = PIDDebug[0][0] * error + PIDDebug[0][2] * derivitive;
  lift(output);
  primaryLastVal = currentVal;
}

int secondaryLastVal = 0;
void secondaryLiftPID(int desired)
{
  int currentVal = analogRead(liftSetUp.secondaryLeft);
  float error = desired - currentVal;
  float derivitive = currentVal - secondaryLastVal;
  float output = PIDDebug[1][0] * error + PIDDebug[1][2] * derivitive;
  secondaryLift(output);
  secondaryLastVal = currentVal;
}
/*
int leftDriveLastVal = 0;
int rightDriveLastVal = 0;
void drivePID(int leftDesired, int rightDesired)
{
  int leftCurrentVal = encoderGet(leftEnc);
  float leftError = leftDesired - leftCurrentVal;
  float leftDerivitive = leftCurrentVal - leftDriveLastVal;
  float leftOutput = PIDDebug[2][0] * leftError + PIDDebug[2][2] * leftDerivitive;
  leftDriveLastVal = leftCurrentVal;

  int rightCurrentVal = encoderGet(rightEnc);
  float rightError = rightDesired - rightCurrentVal;
  float rightDerivitive = rightCurrentVal - rightDriveLastVal;
  float rightOutput = PIDDebug[3][0] * rightError + PIDDebug[3][2] * rightDerivitive;
  rightDriveLastVal = rightCurrentVal;

  drive(leftOutput, rightOutput);
}
*/
