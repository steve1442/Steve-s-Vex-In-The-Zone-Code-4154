#ifndef _GENERALFUNCTIONS_H_
#define _GENERALFUNCTIONS_H_

void lift(int pwm); // A basic function to control the lift whether it be an elevator or a four bar

void secondaryLift(int pwm); // A basic function to control the secondary lift system whether that be chain bar or four bar

void drive(int left, int right); // A basic function to control the chassis or drive of the robot using seperate integers for left and right control

void roller(int pwm); // A basic function for controlling the claw or in this case a roller

void mogo(int pwm); // A basic function for controlling the mobile goal or mogo

int controller(bool type, int controllerNum, int Channel, int button); // A basic function for getting a controller value
#define analog true
#define digital false

#endif
