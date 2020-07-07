#include "main.h"
#ifndef CLOSED_LOOP
#define CLOSED_LOOP



pros::Controller controller(CONTROLLER_MASTER);
pros::Motor rDriveT(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rDriveB(2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveT(3, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveB(4, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

void right_move(float speed){
    rDriveT.move(speed);
    rDriveB.move(speed);
}

void left_move(float speed){
    lDriveT.move(speed);
    lDriveB.move(speed);
}

void chas_move(float lspeed, float rspeed){
    lDriveT.move(lspeed);
    lDriveB.move(lspeed);
    rDriveT.move(rspeed);
    rDriveB.move(rspeed);
}


#endif