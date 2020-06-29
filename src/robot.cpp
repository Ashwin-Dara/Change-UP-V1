____________________________________________ file: robot.cpp
#include “main.h” 
#include “robot.h”  
____________________________________________
void opControl() {
    pros::Controller master(CONTROLLER_MASTER);
    pros::Motor rightMotorOne(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
    pros::Motor rightMotorTwo(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
    pros::Motor leftMotorOne(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
    pros::Motor leftMotorTwo(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
    pros::Motor intakeMotorOne(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
    pros::Motor intakeMotorTwo(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
    pros::Motor flywheel(1, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);

}
