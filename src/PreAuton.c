#include "main.h"
#include <string.h>

int select = -1, menu = 0, menuMax = 3, auton = 1, currLCD = 0, lastLCD = 0;

void runPreAuton()
{
  char *screens1[16][3] = {"    >Auton 1    ",  "    >Auton 2    ",  "    >Auton 3    "};
  char *screens2[3] = {"    20 point    ",  "    Plcehold    ",  "ha i got nothing"};
  while (select == -1)
  {
    currLCD = lcdReadButtons(uart2);
    if (lastLCD == 0 && (currLCD == LCD_BTN_LEFT || currLCD == LCD_BTN_RIGHT)) menu = ( (int)(menu + (currLCD - 2.5) / 1.5) + menuMax) % menuMax;
    if (lastLCD == 0 && currLCD == LCD_BTN_CENTER){ select = menu; auton = menu; }
    lcdPrint(uart2, 1, screens1[15][menu]);  lcdPrint(uart2, 2, screens2[menu]);
    lastLCD = currLCD;
  }
}

void initPreAuton()
{
  if (lcdReadButtons(uart2) != 0)
  {
    runPreAuton();
  }
}
