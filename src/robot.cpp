#include "main.h"
#include "robot.h"


pros::Motor FLWheel (1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor FRWheel (2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor BLWheel (3, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor BRWheel (4, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Motor fly (5, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
pros::Motor IntakeL (6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
pros::Motor IntakeR (7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
pros::Controller joystick (CONTROLLER_MASTER);
