#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *

 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	pros::Controller master(CONTROLLER_MASTER);
	pros::Motor motor1(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
	pros::Motor leftMotor(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
	pros::Motor rightMotor(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
	int push = 0;

	int rightYaxis, leftYaxis;




//assignment 1 

	while (true) {
		if(master.get_digital(DIGITAL_A)) {
			push = push + 1;
		}
			if (push == 1) {
				motor1.move_velocity(70);
			}

			else if (push == 2) {
				motor1.move_velocity(-70);
			}

			else if (push == 3) {
				motor1.move_velocity(0);
			}

			else if (push >= 4) {
				push = 1;
			}
		}
	
//assignment 2
	while (true) {
		rightYaxis = master.get_analog(ANALOG_RIGHT_Y);
		leftYaxis = master.get_analog(ANALOG_LEFT_Y);		
		if(abs(master.get_analog(ANALOG_RIGHT_Y)) > 2)  {
			rightMotor.move(rightYaxis);		
		}
		else
		{
			rightMotor.move(0);
		}
		if(master.get_analog(ANALOG_LEFT_Y) > 2 && master.get_analog(ANALOG_LEFT_Y)< -2) {
			leftMotor.move(leftYaxis);
		}
		else
		{
			leftMotor.move(0);
		}


	}	
}


	

