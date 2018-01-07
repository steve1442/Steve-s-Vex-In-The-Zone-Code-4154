#include "main.h"

int debugScreen = 0, lastDebugJT = 0;
const int maxMenus = 2, bound = 100;
void LCDDebugScreens()
{
  int debugJT = controller(analog, 1, 4, JOY_DOWN);
  if(bound <= abs(debugJT) && bound > abs(lastDebugJT)){debugScreen = (debugScreen + maxMenus + debugJT/abs(debugJT)) % maxMenus;}
  switch(debugScreen)
  {
    case 0:
    lcdPrint( uart1, 1, "   Main Bat %d", powerLevelMain());
    lcdPrint(uart1, 2, "Back-up Bat %d", powerLevelMain());
    break;
    case 1:
    lcdPrint(uart1, 1, "hek");
    lcdPrint(uart1, 2, "runtime:  %lum%lus", millis()/60000, millis()%60000/1000);
    break;
    case 2:
    lcdPrint(uart1, 1, "hek");
    lcdPrint(uart1, 2, "hek");
    break;
    default:
    lcdPrint(uart1, 1, "Error");
    lcdPrint(uart1, 2, "No Debug Screen");
    break;
  }
  lastDebugJT = debugJT;
  konamicodefunc();
  delay(2);
}

void LCDSetUp(bool backlight, int lcds)
{
  lcdInit(uart1);
  lcdSetBacklight(uart1, backlight);
  if(lcds == 2)
  {
    lcdInit(uart2);
    lcdSetBacklight(uart2, backlight);
  }
}
