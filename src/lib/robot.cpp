#include "main.h"
#include "robot.h"
//left motors are reversed
pros::Controller controller(CONTROLLER_MASTER);
pros::Motor rDriveT(DRIVE_RT, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rDriveB(DRIVE_RB, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveT(DRIVE_LT, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveB(DRIVE_LB, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

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