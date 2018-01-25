
#include "main.h"

void initializeIO() {
}

int leftime, rightime;
void initialize() {
  gyroInit(6, 1);
  imeInitializeAll ();
  LCDSetUp(true, 1);
  MotorSetUp(2, 3, 0, 8, 9, 0, 5, 6, 10, 0, 4, 7, 1);
  SensorSetUp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  ControllerSetUp( 1, 6, UPDOWN, 1, 8, UPDOWN, 1, 5, UPDOWN, 1, 7, UPDOWN);
}
