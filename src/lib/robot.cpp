#include "main.h"
#include "../include/lib/robot.h"
using namespace pros; 

int sgn(int x){
    int y = (x<0) ? 1 : -1; 
    return y; 
}

Controller joystick(E_CONTROLLER_MASTER);
Motor rm1(DRIVE_RIGHT_1, GREEN, false, DEGREES);
Motor rm2(DRIVE_RIGHT_2, GREEN, false, DEGREES);

Motor lm1(DRIVE_LEFT_1, GREEN, true, DEGREES);
Motor lm2(DRIVE_LEFT_2, GREEN, true, DEGREES);