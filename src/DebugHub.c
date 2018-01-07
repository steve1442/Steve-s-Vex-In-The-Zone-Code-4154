#include "main.h"


void DebugHub()
{
  bool debugHubBreak = true;
  while(debugHubBreak)
  {
    lcdPrint(uart1, 1, "8U:PID|8D:JTCtrl");
    lcdPrint(uart1, 2, "8L:FUN|8R:RETURN");

    if(controller(digital, 1, 8, JOY_UP))
    {

    }

    else if(controller(digital, 1, 8, JOY_DOWN))
    {

    }

    else if(controller(digital, 1, 8, JOY_LEFT))
    {
      
    }

    else if(controller(digital, 1, 8, JOY_RIGHT))
    {
      debugHubBreak = false;
    }

    delay(2);
  }
}
