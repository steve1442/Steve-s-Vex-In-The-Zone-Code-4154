#include "main.h"

void operatorControl()
{
	TaskHandle UPDATE = taskRunLoop(update, 10);
	TaskHandle CONTROL = taskRunLoop(control, 10);
	TaskHandle LCDDEBUG = taskRunLoop(LCDDebugScreens, 10);
	TaskHandle PID = taskRunLoop(pid, 10);
	while (1)
	{
		delay(20);
	}
	taskDelete(UPDATE);
	taskDelete(CONTROL);
	taskDelete(LCDDEBUG);
	taskDelete(PID);
}
