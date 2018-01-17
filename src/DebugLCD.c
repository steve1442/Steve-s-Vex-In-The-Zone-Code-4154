#include "main.h"

int debugScreen = 0, lastDebugJT = 0;
const int maxMenus = 4, bound = 100;
void LCDDebugScreens()
{
  imeGet(0, &leftime);
  imeGet(1, &rightime);
  int debugJT = controller(analog, 1, 4, JOY_DOWN);
  if(bound <= abs(debugJT) && bound > abs(lastDebugJT)){debugScreen = (debugScreen + maxMenus + debugJT/abs(debugJT)) % maxMenus;}
  switch(debugScreen)
  {
    case 0:
    lcdPrint( uart2, 1, "   Main Bat %d", powerLevelMain());
    lcdPrint(uart2, 2, "Back-up Bat %d", powerLevelMain());
    break;
    case 1:
    lcdPrint(uart2, 1, "hek");
    lcdPrint(uart2, 2, "runtime:  %lum%lus", millis()/60000, millis()%60000/1000);
    break;
    case 2:
    lcdPrint(uart2, 1, "secondary %d", analogRead(5));
    lcdPrint(uart2, 2, "hek");
    break;
    case 3:
    lcdPrint(uart2, 1, "left %d", leftime);
    lcdPrint(uart2, 2, "right %d", rightime);
    break;
    default:
    lcdPrint(uart2, 1, "Error");
    lcdPrint(uart2, 2, "No Debug Screen");
    break;
  }
  lastDebugJT = debugJT;
  konamicodefunc();
  delay(2);
}

void LCDSetUp(bool backlight, int lcds)
{
  lcdInit(uart2);
  lcdSetBacklight(uart2, backlight);
  if(lcds == 2)
  {
    lcdInit(uart2);
    lcdSetBacklight(uart2, backlight);
  }
}
