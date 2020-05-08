#include "main.h"
#include "../include/lib/drive.h"
namespace drive{

void operatorControl(){
    int rightPower, leftPower; 
    if(abs(joystick.get_analog(ANALOG_RIGHT_Y)) > 2)
        rightPower = joystick.get_analog(ANALOG_RIGHT_Y);
    else rightPower = 0; 
    if(abs(joystick.get_analog(ANALOG_LEFT_Y)) > 2)
        leftPower = joystick.get_analog(ANALOG_LEFT_Y);
    else leftPower = 0; 
    rm1.move_voltage(rightPower * V_CONST);
    rm2.move_voltage(rightPower * V_CONST);
    lm1.move_voltage(leftPower * V_CONST);
    lm2.move_voltage(leftPower * V_CONST);
    }
}