#include "main.h"
#include "PID.h"
#ifndef MOVEMENT_H_
#define MOVEMENT_H_

void move(int target, bool ask_slew = false, int slew_rate = 0);
void turn(int target, bool ask_slew = false, int slew_rate = 0);

//void turn(int target, bool ask_slew, int slew_rate);
#endif
