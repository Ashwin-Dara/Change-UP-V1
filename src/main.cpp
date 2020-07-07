#include "main.h"
#include "robot.h"

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
	/*
///variables
int press_amount = 2;
int target = 0;
bool rising_edge;
float rightYaxis, leftYaxis;



 
/// this is the new assignment 2, the 2-button toggle with rising edge and mod operator
while (true){

	if (joystick.get_digital(DIGITAL_A) && !rising_edge) {

	      press_amount ++;

		}
	
	if (press_amount %2 == 1) {

			target = 150;

	}

	else if (press_amount %2 == 0) {
		
			target = 0;

	}

	

	else {
		
		pros::delay (20);

	}


	}

rising_edge = joystick.get_digital(DIGITAL_A); //rising edge protector
pros::delay (20);




	/*
/// assignment 2 is here


	rightYaxis = joystick.get_analog(ANALOG_RIGHT_Y);
	leftYaxis = joystick.get_analog(ANALOG_LEFT_Y);



	if (abs(rightYaxis > 2)){
	
		right_motor.move(rightYaxis);

	}

	else{ 
		right_motor.move(0);
	}

	if (abs(leftYaxis > 2)){
	
		left_motor.move(leftYaxis);


	}


*/






}

	
