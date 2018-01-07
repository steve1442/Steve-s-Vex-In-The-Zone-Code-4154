#include "main.h"

int varControl(int variable, int joystick, int channel, int axis)
{
  if(axis == 1)
  {
    if(joystickGetDigital(joystick, channel, JOY_UP))
    {
      variable++;
    }
    else if(joystickGetDigital(joystick, channel, JOY_DOWN))
    {
      variable--;
    }
  }
  else if(axis == 2)
  {
    if(joystickGetDigital(joystick, channel, JOY_LEFT))
    {
      variable++;
    }
    else if(joystickGetDigital(joystick, channel, JOY_RIGHT))
    {
      variable--;
    }
  }
  return variable;
}

int basicFuncControl(int pwm, int joystick, int channel, int axis)
{
  int output = 0;
  if(axis == 1)
  {
    output = pwm * (joystickGetDigital(joystick, channel, JOY_UP) - joystickGetDigital(joystick, channel, JOY_DOWN));
  }
  else if(axis == 2)
  {
    output = pwm * (joystickGetDigital(joystick, channel, JOY_LEFT) - joystickGetDigital(joystick, channel, JOY_RIGHT));
  }
  return output;
}
