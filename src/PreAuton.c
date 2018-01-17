#include "main.h"

void runPreAuton()
{
  int menu = 0;
  int menuMax = 3;
  int auton = 1; //default auton
  int currLCD = 0;
  int lastLCD = 0;
  int select = -1;
  char *screens1[3] = {"    >Auton 1    ",  "    >Auton 2    ",  "    >Auton 3    "};
  char *screens2[3] = {"    20 point    ",  "    Plcehold    ",  "ha i got nothing"};
  while (select == -1)
  {
    currLCD = lcdReadButtons(uart2);
    if (lastLCD == 0 && (currLCD == LCD_BTN_LEFT || currLCD == LCD_BTN_RIGHT)) menu = ( (int)(menu + (currLCD - 2.5) / 1.5) + menuMax) % menuMax;
    if (lastLCD == 0 && currLCD == LCD_BTN_CENTER){ select = menu; auton = menu; }
    lcdPrint(uart2, 1, screens1[menu]);  lcdPrint(uart2, 2, screens2[menu]);
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
