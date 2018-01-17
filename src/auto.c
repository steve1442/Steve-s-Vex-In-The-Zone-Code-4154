
#include "main.h"

void autonomous() {

  TaskHandle UPDATE = taskRunLoop(update, 10);
  imeReset(1);
  imeReset(0);
  roller(-127);
  wait(30);
  roller(0);
  roller(127);
  wait(500);
  roller(0);
  secondaryLift(127);
  mogo(-127);
  wait(2000);
  secondaryLift(0);
  mogo(0);
  while(1500 > leftime){
    lcdPrint(uart2, 1, "works");
  drive(-127, 127);}
  drive(0,0);
  imeReset(1);
  imeReset(0);
  mogo(127);
  wait(1500);
  mogo(0);
  roller(-127);
  wait(700);
  roller(0);
  while(1400 > -leftime){lcdPrint(uart2, 1, "works");
  drive(127, -50);}
  drive(0,0);
  imeReset(1);
  imeReset(0);
  while(600 > -rightime){lcdPrint(uart2, 1, "works");
  drive(20, 127);}
  drive(0,0);
  imeReset(1);
  imeReset(0);
  while(900 > leftime){
    lcdPrint(uart2, 1, "works");
  drive(-127, 127);}
  drive(0,0);
  mogo(-127);
  wait(700);
  mogo(0);
  drive(127,-127);
  wait(200);
  mogo(-127);
  wait(500);
  mogo(0);
  drive(0,0);
  taskDelete(UPDATE);

/*TaskHandle UPDATE = taskRunLoop(update, 10);
imeReset(1);
imeReset(0);
roller(-127);
wait(30);
roller(0);
roller(127);
wait(500);
roller(0);
secondaryLift(127);
mogo(-127);
wait(2000);
secondaryLift(0);
mogo(0);
while(1500 > leftime){
  lcdPrint(uart2, 1, "works");
drive(-127, 127);}
drive(0,0);
imeReset(1);
imeReset(0);
mogo(127);
wait(1500);
mogo(0);
roller(-127);
wait(700);
roller(0);
while(1400 > -leftime){lcdPrint(uart2, 1, "works");
drive(127, -50);}
drive(0,0);
imeReset(1);
imeReset(0);
while(600 > -rightime){lcdPrint(uart2, 1, "works");
drive(20, 127);}
drive(0,0);
imeReset(1);
imeReset(0);
while(900 > leftime){
  lcdPrint(uart2, 1, "works");
drive(-127, 127);}
drive(0,0);
mogo(-127);
wait(700);
mogo(0);
drive(127,-127);
wait(200);
mogo(-127);
wait(500);
mogo(0);
drive(0,0);
taskDelete(UPDATE);
*/
}
