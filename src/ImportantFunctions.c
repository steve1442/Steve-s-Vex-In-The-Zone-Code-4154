#include "main.h"

void update()
{
  motorSet(1, motor[1]);motorSet(2, motor[2]);motorSet(3, motor[3]);motorSet(4, motor[4]);motorSet(5, motor[5]);
  motorSet(6, motor[6]);motorSet(7, motor[7]);motorSet(8, motor[8]);motorSet(9, motor[9]);motorSet(10, motor[10]);
  delay(2);
}

void control()
{
  drive(controller(analog, 1, 4, JOY_UP), controller(analog, 1, 3, JOY_UP));
  PIDDesired[0] = varControl(PIDDesired[0], controllerSetUp.liftJT, controllerSetUp.liftChannel, controllerSetUp.liftAxis);
  PIDDesired[1] = varControl(PIDDesired[1], controllerSetUp.secondaryLiftJT, controllerSetUp.secondaryLiftChannel, controllerSetUp.secondaryLiftAxis);
  mogo(basicFuncControl(127, controllerSetUp.mogoJT, controllerSetUp.mogoChannel, controllerSetUp.mogoAxis));
  roller(basicFuncControl(127, controllerSetUp.intakeJT, controllerSetUp.intakeChannel, controllerSetUp.intakeAxis));
  delay(2);
}
