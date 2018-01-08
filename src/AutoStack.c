#include "main.h"

const int grabCone = 1000;

int waitUntilTop = 1000;

int secondaryArmPos[2] = {1000, 1000};

void AutoStack()
{
  roller(127);
  while(grabCone > analogRead(liftSetUp.primaryLeftPot))
  {
    primaryLiftPID(grabCone);
    delay(2);
  }
  while(ultrasonicGet(sonar) > 8) // cancer
  {
    primaryLiftPID(waitUntilTop);
    waitUntilTop++;
    delay(2);
  }
  while(analogRead(liftSetUp.secondaryLeftPot < secondaryArmPos[1]))
  {
    secondaryLiftPID(secondaryArmPos[1]);
    delay(2);
  }
  roller(-127);
  wait(100);
  roller(0);
  while(analogRead(liftSetUp.secondaryLeftPot > secondaryArmPos[0]))
  {
    secondaryLiftPID(secondaryArmPos[0]);
    delay(2);
  }
  while(analogRead(liftSetUp.primaryLeftPot < grabCone))
  {
    primaryLiftPID(grabCone);
    delay(2);
  }
}
