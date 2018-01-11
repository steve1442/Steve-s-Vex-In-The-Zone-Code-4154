#include "main.h"

char motor[11] = {0,0,0,0,0,0,0,0,0,0,0};

void lift(int pwm)
{
  motor[/*liftSetUp.primaryLef*/5] = pwm;
  motor[/*liftSetUp.primaryRight*/6] = pwm;
}

void secondaryLift(int pwm)
{
  motor[liftSetUp.secondaryLeft] = pwm;
  motor[liftSetUp.secondaryRight] = pwm;
}

void drive(int left, int right)
{
  motor[/*driveSetUp.firstLeft*/3] = left;
  motor[/*driveSetUp.secondLeft*/2] = left;
  motor[/*driveSetUp.secondLeft*/2] = left;
  motor[/*driveSetUp.firstRight*/8] = right;
  motor[/*driveSetUp.secondRight*/9] = right;
  motor[/*driveSetUp.secondRight*/9] = right;
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
