#include "main.h"

int toggle;
bool lastclawggle;
int pidswitch = 0;
int constantswitch = 0;
void debug()  // yea this was ctrl + c  ctrl + p into here, sorry its 4:38 in the morning and im just too tired to make the function to make this really small and neat so enjoy
{
	bool lastconstswitchup = false, lastconstswitchdown = false, lastpidswitchup = false, lastpidswitchdown = false, lastconstup = false, lastconstdown = false;
	while(1)
	{
	bool pidswitchup = joystickGetDigital(1, 6, JOY_UP);
	bool pidswitchdown = joystickGetDigital(1, 6, JOY_DOWN);
	bool constantswitchup = joystickGetDigital(1, 8, JOY_LEFT);
	bool constantswitchdown = joystickGetDigital(1, 8, JOY_RIGHT);
	bool desiredvalup = joystickGetDigital(1, 7, JOY_UP);
	bool desiredvaldown = joystickGetDigital(1, 7, JOY_DOWN);
	bool constantup = joystickGetDigital(1, 8, JOY_UP);
	bool constantdown = joystickGetDigital(1, 8, JOY_DOWN);
	if(pidswitchup && !lastpidswitchup){pidswitch+= 1;}
	else if(pidswitchdown && !lastpidswitchdown){pidswitch-= 1;}
	if(constantswitchup && !lastconstswitchup){constantswitch-= 1;}
	else if(constantswitchdown && !lastconstswitchdown){constantswitch+= 1;}
	if(constantup && !lastconstup){PIDDebug[pidswitch][constantswitch]+= 0.1;}
	else if(constantdown && !lastconstdown){PIDDebug[pidswitch][constantswitch]-= 0.1;}
	if(pidswitch > 4){pidswitch = 0;}
	else if(pidswitch < 0){pidswitch = 4;}
	if(constantswitch > 2){constantswitch = 0;}
	else if(constantswitch < 0){constantswitch = 2;}
	if(desiredvalup){PIDDesired[pidswitch]-= 3;}
	else if(desiredvaldown){PIDDesired[pidswitch]+= 3;}
	lcdPrint(uart1, 1, "PID %d  D %d", pidswitch, PIDDesired[pidswitch]);
	switch(constantswitch){
		case 0:	lcdPrint(uart1, 2, "kP %f", PIDDebug[pidswitch][0]);break;
		case 1:	lcdPrint(uart1, 2, "kI %f", PIDDebug[pidswitch][1]);break;
		case 2:lcdPrint(uart1, 2, "kD %f", PIDDebug[pidswitch][2]);break;
		default:lcdPrint(uart1, 1, "PID Not found");lcdPrint(uart1, 2, "Make Better Code");break;}
	lastpidswitchup = pidswitchup, lastpidswitchdown = pidswitchdown, lastconstswitchup = constantswitchup,	lastconstswitchdown = constantswitchdown, lastconstup = constantup,	lastconstdown = constantdown;
	delay(2);
	}
}

void DebugHub()
{
  bool debugHubBreak = true;
  while(debugHubBreak)
  {
    lcdPrint(uart1, 1, "8U:PID|8D:JTCtrl");
    lcdPrint(uart1, 2, "8L:FUN|8R:RETURN");

    if(controller(digital, 1, 8, JOY_UP))
    {
      debug();
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
