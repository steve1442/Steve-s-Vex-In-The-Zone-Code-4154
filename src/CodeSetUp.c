#include "main.h"

void MotorSetUp(int firstLeftDrive, int secondLeftDrive, int thirdLeftDrive, int firstRightDrive, int secondRightDrive, int thirdRightDrive, int leftLift, int rightLift, int leftSecondaryLift, int rightSecondaryLift, int leftMogo, int rightMogo ,int clawroller)
{
  driveSetUp.firstLeft = firstLeftDrive;
  driveSetUp.secondLeft = secondLeftDrive;
  driveSetUp.thirdLeft = thirdLeftDrive;
  driveSetUp.firstRight = firstRightDrive;
  driveSetUp.secondRight = secondRightDrive;
  driveSetUp.thirdRight = thirdRightDrive;
  liftSetUp.primaryLeft = leftLift;
  liftSetUp.primaryRight = rightLift;
  liftSetUp.secondaryLeft = leftSecondaryLift;
  liftSetUp.secondaryRight = rightSecondaryLift;
  mogoSetUp.left = leftMogo;
  mogoSetUp.right = rightMogo;
  intakeSetUp.primaryIntake = clawroller;
}

void SensorSetUp(int driveLeftTop, int driveLeftBottom, int driveRightTop, int driveRightBottom, int primaryLeft, int primaryRight, int secondaryLeft, int secondaryRight, int orange_port_number, int yellow_port_number)
{
  driveSetUp.leftEncoderTopWire = driveLeftTop;
  driveSetUp.leftEncoderBottomWire = driveLeftBottom;
  liftSetUp.primaryLeft = primaryLeft;
  liftSetUp.primaryRight = primaryRight;
  liftSetUp.secondaryLeft = secondaryLeft;
  liftSetUp.secondaryRight = secondaryRight;
  sonar = ultrasonicInit(orange_port_number, yellow_port_number);
  leftEnc = encoderInit(driveLeftTop, driveRightBottom, false);
  rightEnc = encoderInit(driveRightTop, driveRightBottom, true);
}

void ControllerSetUp(int liftJT, int liftChannel, int liftAxis, int secondaryLiftJT, int secondaryLiftChannel, int secondaryLiftAxis, int mogoJT, int mogoChannel, int mogoAxis, int intakeJT, int intakeChannel,int intakeAxis)
{
  controllerSetUp.liftJT = liftJT;
  controllerSetUp.liftChannel = liftChannel;
  controllerSetUp.liftAxis = liftAxis;
  controllerSetUp.secondaryLiftJT = secondaryLiftJT;
  controllerSetUp.secondaryLiftChannel = secondaryLiftChannel;
  controllerSetUp.secondaryLiftAxis = secondaryLiftAxis;
  controllerSetUp.mogoJT = mogoJT;
  controllerSetUp.mogoChannel = mogoChannel;
  controllerSetUp.mogoAxis = mogoAxis;
  controllerSetUp.intakeJT = intakeJT;
  controllerSetUp.intakeChannel = intakeChannel;
  controllerSetUp.intakeAxis = intakeAxis;
}
