#ifndef CodeSetUp_H_

#define CodeSetUp_H_

#include "main.h"

extern char motor[11];

struct driveSetUp
{
  int firstLeft, secondLeft, thirdLeft;
  int firstRight, secondRight, thirdRight;
  int leftEncoderTopWire;
  int leftEncoderBottomWire;
  int rightEncoderTopWire;
  int rightEncoderBottoWire;
}driveSetUp;

struct liftSetUp
{
  int primaryLeft;
  int primaryRight;
  int secondaryLeft;
  int secondaryRight;
  int primaryLeftPot;
  int primaryRightPot;
  int secondaryLeftPot;
  int secondaryRightPot;
}liftSetUp;

struct mogoSetUp
{
  int left;
  int right;
}mogoSetUp;

struct intakeSetUp
{
  int primaryIntake;
  int secondaryIntake;
}intakeSetUp;

struct controllerSetUp
{
  int liftJT, liftChannel, liftAxis,
  secondaryLiftJT, secondaryLiftChannel, secondaryLiftAxis,
  mogoJT, mogoChannel, mogoAxis,
  intakeJT, intakeChannel, intakeAxis;
}controllerSetUp;
// 8, 7, 0, 2, 3, 0, 5, 6, 10, 0, 4, 7, 1
void MotorSetUp(int firstLeftDrive, int secondLeftDrive, int thirdLeftDrive, int firstRightDrive, int secondRightDrive, int thirdRightDrive, int leftLift, int rightLift, int leftSecondaryLift, int rightSecondaryLift, int leftMogo, int rightMogo ,int clawroller);
Ultrasonic sonar;
Encoder leftEnc;
Encoder rightEnc;
// 0, 0, 0, 0, 0, 0, 0, 0
void SensorSetUp(int driveLeftTop, int driveLeftBottom, int driveRightTop, int driveRightBottom, int primaryLeft, int primaryRight, int secondaryLeft, int secondaryRight, int orange_port_number, int yellow_port_number);
// 1, 6, UPDOWN, 1, 8, UPDOWN, 1, 5, UPDOWN, 1, 7, UPDOWN
void ControllerSetUp(int liftJT, int liftChannel, int liftAxis, int secondaryLiftJT, int secondaryLiftChannel, int secondaryLiftAxis, int mogoJT, int mogoChannel, int mogoAxis, int intakeJT, int intakeChannel,int intakeAxis);

#endif
