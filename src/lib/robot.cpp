#include "main.h"
#include "robot.h"

//left motors are reversed
pros::Controller controller(CONTROLLER_MASTER);
pros::Motor rDriveT(DRIVE_RT, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES); 
pros::Motor rDriveB(DRIVE_RB, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveT(DRIVE_LT, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor lDriveB(DRIVE_LB, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor lIntake(INTAKE_LEFT, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor rIntake(INTAKE_RIGHT, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor indexer(INDEXER, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor outake(OUTAKE, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
pros::Imu imu(IMU_PORT);
pros::ADIAnalogIn index_bottom(INDEX_BOTTOM_LINE_PORT);
pros::ADIAnalogIn index_top(INDEX_TOP_LINE_PORT);

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

void reset_encoders(){
    lDriveT.tare_position();
    lDriveB.tare_position();
    rDriveT.tare_position();
    rDriveB.tare_position();
}