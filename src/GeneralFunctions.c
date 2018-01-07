#include "main.h"

char motor[11] = {0,0,0,0,0,0,0,0,0,0,0};

void lift(int pwm)
{
  motor[liftSetUp.primaryLeft] = pwm;
  motor[liftSetUp.primaryRight] = pwm;
}

void secondaryLift(int pwm)
{
  motor[liftSetUp.secondaryLeft] = pwm;
  motor[liftSetUp.secondaryRight] = pwm;
}

void drive(int left, int right)
{
  motor[driveSetUp.firstLeft] = left;
  motor[driveSetUp.secondLeft] = left;
  motor[driveSetUp.secondLeft] = left;
  motor[driveSetUp.firstRight] = right;
  motor[driveSetUp.secondRight] = right;
  motor[driveSetUp.secondRight] = right;
}

void roller(int pwm)
{
  motor[intakeSetUp.primaryIntake] = pwm;
}

void mogo(int pwm)
{
  motor[mogoSetUp.left] = pwm;
  motor[mogoSetUp.right] = pwm;
}

int controller(bool type, int controllerNum, int Channel, int button)
{
  int x;
  if(type)
  {
    x = joystickGetAnalog(controllerNum, Channel);
  }
  else if(!type)
  {
    x = joystickGetDigital(controllerNum, Channel, button);
  }
  return x;
}
