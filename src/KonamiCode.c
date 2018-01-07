#include "main.h"

int konami = 1;
bool menutogg = 0;
bool lastup = 0, lastdown = 0, lastleft = 0, lastright = 0;
void konamicodefunc()
{
	bool up = joystickGetDigital(1, 8, JOY_UP);
	bool down = joystickGetDigital(1, 8, JOY_DOWN);
	bool left = joystickGetDigital(1, 8, JOY_LEFT);
	bool right = joystickGetDigital(1, 8, JOY_RIGHT);

  if((konami == 1 && up && !lastup) || (konami == 2 && up && !lastup) || (konami == 3 && down && !lastdown) || (konami == 4 && down && !lastdown) || (konami == 5 && left && !lastleft) || (konami == 6 && right && !lastright) ||
  (konami == 7 && left && !lastleft) || (konami == 8 && right && !lastright))
  {
    konami++;
  }

	else if( (up && !lastup) || (down && !lastdown) || (left && !lastleft)|| (right && !lastright))
  {
    konami = 1;
  }

	else if(konami == 9)
  {
    DebugHub();
  }

	lastup = up,
  lastdown = down,
  lastleft = left,
  lastright = right;
  delay(2);
}
