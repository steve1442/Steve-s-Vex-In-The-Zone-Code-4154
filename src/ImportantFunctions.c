#include "main.h"

void update()
{
  motorSet(1, motor[1]);motorSet(2, motor[2]);motorSet(3, motor[3]);motorSet(4, motor[4]);motorSet(5, motor[5]);
  motorSet(6, motor[6]);motorSet(7, motor[7]);motorSet(8, motor[8]);motorSet(9, motor[9]);motorSet(10, motor[10]);
  imeGet(0, &leftime); imeGet(1, &rightime);
  delay(2);
}

bool autostacking = false;
int stackSize;

void control()
{
  drive(-controller(analog, 1, 3, JOY_UP), controller(analog, 1, 2, JOY_UP));
  mogo(basicFuncControl(127, controllerSetUp.mogoJT, controllerSetUp.mogoChannel, controllerSetUp.mogoAxis));
//  if(!autostacking)
//  {
    lift(basicFuncControl(127, controllerSetUp.liftJT, controllerSetUp.liftChannel, controllerSetUp.liftAxis));
    secondaryLift(basicFuncControl(127, controllerSetUp.secondaryLiftJT, controllerSetUp.secondaryLiftChannel, controllerSetUp.secondaryLiftAxis));
    //PIDDesired[0] = varControl(PIDDesired[0], controllerSetUp.liftJT, controllerSetUp.liftChannel, controllerSetUp.liftAxis);
    //PIDDesired[1] = varControl(PIDDesired[1], controllerSetUp.secondaryLiftJT, controllerSetUp.secondaryLiftChannel, controllerSetUp.secondaryLiftAxis);
    roller(basicFuncControl(127, controllerSetUp.intakeJT, controllerSetUp.intakeChannel, controllerSetUp.intakeAxis));
//  }
//  if(controller(digital, 1, 7, JOY_UP))
//  {
//    autostacking = true;
//    stackSize++;
//  }
  delay(2);
}
