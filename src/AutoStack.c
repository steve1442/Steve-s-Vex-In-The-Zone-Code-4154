#include "main.h"

const int grabCone = 1000;

int waitUntilTop = 1000;

int secondaryArmPos[2] = {1000, 1000};

void AutoStack()
{
  roller(127);
  while(grabCone > analogRead(liftSetUp.primaryLeftPot))
  {
    PIDDesired[0] = grabCone;
    delay(2);
  }
  while(ultrasonicGet(sonar) > 8) // Wait until for the big arm
  {
    PIDDesired[0] = waitUntilTop;
    waitUntilTop++;
    delay(2);
  }
  while(analogRead(liftSetUp.secondaryLeftPot < secondaryArmPos[1]))
  {
    PIDDesired[1] = secondaryArmPos[1];
    delay(2);
  }
  roller(-127);
  wait(100);
  roller(0);
  while(analogRead(liftSetUp.secondaryLeftPot > secondaryArmPos[0]))
  {
    PIDDesired[1] = secondaryArmPos[0];
    delay(2);
  }
  while(analogRead(liftSetUp.primaryLeftPot < grabCone))
  {
    PIDDesired[1] = grabCone;
    delay(2);
  }
  autostacking = false;
}
