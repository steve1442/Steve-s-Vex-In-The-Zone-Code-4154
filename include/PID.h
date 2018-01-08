#ifndef _PID_H_
#define _PID_H_

extern float PIDDebug[5][3];
extern int PIDDesired[5];

void primaryLiftPID(int desired);

void secondaryLiftPID(int desired);

#endif
