#include "main.h"

void AutoStack()
{
  lift(-127);
  roller(127);
  wait(200); // cancer
  roller(75);
  while(ultrasonicGet(sonar) > 8) // cancer
  {
    lift(127);
  }
  lift(30);
  secondaryLift(127);
  wait(200); // cancer
  secondaryLift(0);
  roller(-127);
  wait(50); // cancer
  roller(0);
  secondaryLift(-127);
  wait(200); // cancer
  lift(-127);
  wait(300); // cancer
  lift(0);
}
