#include "main.h"
#include <string.h>

int select = -1, menu = 0, menuMax = 6, auton = 1, currLCD = 0, lastLCD = 0;

void autonselect()
{
  while(select == -1)
  {
    currLCD = lcdReadButtons(uart2);
    if (lastLCD == 0 && (currLCD == LCD_BTN_LEFT || currLCD == LCD_BTN_RIGHT)) menu = ( (int)(menu + (currLCD - 2.5) / 1.5) + menuMax) % menuMax;
    if (lastLCD == 0 && currLCD == LCD_BTN_CENTER){ select = menu; auton = menu; }
    switch(menu)
    {
      case 0:
      lcdPrint(uart2, 1, "Auton 1");
      lcdPrint(uart2, 2, "20 PT Blue");
      break;
      case 1:
      lcdPrint(uart2, 1, "Auton 2");
      lcdPrint(uart2, 2, "10 PT Blue");
      break;
      case 2:
      lcdPrint(uart2, 1, "Auton 3");
      lcdPrint(uart2, 2, "20 PT Red");
      break;
      case 3:
      lcdPrint(uart2, 1, "Auton 4");
      lcdPrint(uart2, 2, "10 PT Red");
      break;
      case 4:
      lcdPrint(uart2, 1, "Skillz");
      lcdPrint(uart2, 2, "probs wont work");
      break;
      default:
      lcdPrint(uart2, 1, "No Auton");
      lcdPrint(uart2, 2, "Sad Bois :(");
      break;
    }
    lastLCD = currLCD;
  }
}
