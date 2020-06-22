#include "main.h"
#include "../include/lib/robot.h"
using namespace pros; 


Controller joystick(E_CONTROLLER_MASTER);
Motor rm1(DRIVE_RIGHT_1, GREEN, false, DEGREES);
Motor rm2(DRIVE_RIGHT_2, GREEN, false, DEGREES);

Motor lm1(DRIVE_LEFT_1, GREEN, true, DEGREES);
Motor lm2(DRIVE_LEFT_2, GREEN, true, DEGREES);

int sgn(int x){
    int y = (x > 0) ? 1 : -1; 
    return y; 
}

void driveVoltageAssign(int rightPower, int leftPower){
    rm1.move_voltage(rightPower);
    rm2.move_voltage(rightPower);
    lm1.move_voltage(leftPower);
    lm2.move_voltage(leftPower);
}


