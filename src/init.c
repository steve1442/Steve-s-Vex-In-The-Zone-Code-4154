
#include "main.h"

void initializeIO() {
}

void initialize() {
  MotorSetUp( 8, 7, 0, 2, 3, 0, 5, 6, 10, 0, 4, 7, 1);
  SensorSetUp( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  ControllerSetUp( 1, 6, UPDOWN, 1, 8, UPDOWN, 1, 5, UPDOWN, 1, 7, UPDOWN);
  LCDSetUp( true, 1);
}
