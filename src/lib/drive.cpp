#include "main.h"
#include "../include/lib/drive.h"
namespace drive{

float powerSpline(float axisInput){
    float denom = (K + A*(std::exp(C*axisInput)));
    float y = (1/denom);
    return float(y);
}

void operatorControl(bool usingSpline){
    if(usingSpline){
    int rightAxis = joystick.get_analog(ANALOG_RIGHT_Y);
    int leftAxis = joystick.get_analog(ANALOG_LEFT_Y);
    int rightPower, leftPower;
    if(abs(joystick.get_analog(ANALOG_RIGHT_Y)) > 2)
        rightPower = (powerSpline(rightAxis) - powerSpline(0));
    if(abs(joystick.get_analog(ANALOG_LEFT_Y)) > 2)
        leftPower = (powerSpline(leftAxis) - powerSpline(0));
    else leftPower = 0; 
    rm1.move_voltage(rightPower * V_CONST);
    rm2.move_voltage(rightPower * V_CONST);
    lm1.move_voltage(leftPower * V_CONST);
    lm2.move_voltage(leftPower * V_CONST);
    } 
    if(!usingSpline){
    int rightAxis = joystick.get_analog(ANALOG_RIGHT_Y);
    int leftAxis = joystick.get_analog(ANALOG_LEFT_Y);
    int rightPower, leftPower;    
    rightPower = rightAxis * 80; 
    leftPower = leftAxis * 80; 
    rm1.move_voltage(rightPower);
    rm2.move_voltage(rightPower);
    lm1.move_voltage(leftPower);
    lm2.move_voltage(leftPower);
        }
    }
}