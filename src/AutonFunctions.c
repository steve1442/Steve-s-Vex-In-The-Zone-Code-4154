#include "main.h"

int leftDriveLastVal = 0;
int rightDriveLastVal = 0;
void distanceDrivePID(int Desired, int distance)
{
  int leftLastVal = 0;
  int rightLastVal = 0;
  int leftCurrentVal = leftime;
  int rightCurrentVal = rightime;
  int leftRotations = leftCurrentVal - leftLastVal;
  int rightRotations = rightCurrentVal - rightLastVal;
  float leftError = Desired - leftRotations;
  float leftDerivitive = leftRotations - leftDriveLastVal;
  float leftOutput = PIDDebug[2][0] * leftError + PIDDebug[2][2] * leftDerivitive;
  leftDriveLastVal = leftCurrentVal;

  float rightError = Desired - rightRotations;
  float rightDerivitive = rightRotations - rightDriveLastVal;
  float rightOutput = PIDDebug[3][0] * rightError + PIDDebug[3][2] * rightDerivitive;
  rightDriveLastVal = rightCurrentVal;

  leftDriveLastVal = leftime;
  rightDriveLastVal = rightime;

  drive(leftOutput, rightOutput);
}

// ITS THIS FILE BTW, THIS ONE THISSSSSSSSSSSS ONEEEEEEEEEE alessandro this is the file. not the other ones
// u have spent 5 minutes looking at trying to find where the fuck i put the gyro code



void gyroTurn(int desired, int fuckhim) // fuck alessandro he wants this function to fucking work
{
  int alessandrosucks = desired - gyroGet(gyro);
  drive(alessandrosucks, alessandrosucks); // if the code does like some spin manuver
  // JUST FUCKING RUN
  // dont really
  // if it starts to spin then put a negative on both the alessandrosucks k?
  // can u do that?
  // good
}
