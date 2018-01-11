#include "main.h"


// im gay - brennan


int leftDriveLastVal = 0;
int rightDriveLastVal = 0;
void distanceDrivePID(int Desired, int distance)
{
  int leftLastVal = 0;
  int rightLastVal = 0;
  int leftCurrentVal = encoderGet(leftEnc);
  int rightCurrentVal = encoderGet(rightEnc);
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

  leftDriveLastVal = encoderGet(leftEnc);
  rightDriveLastVal = encoderGet(rightEnc);

  drive(leftOutput, rightOutput);
}
