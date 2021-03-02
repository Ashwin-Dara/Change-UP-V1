#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
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


void new_programming_skills(){

			/* 
			Double Move function is pretty much the same thing as the regular move function. 
			Parameters: int target, int secondVelocityBound (leave it at 50), velocity, velocity (make them the same number), float slewRate

			We found that typically a slew rate of 0.9 is better for backing away from goals/intaking balls (with a velocity of 25-30)
			while a rate of 1.3 and max velocity of 105 would be ideal for far movements

			To go towards the goals, I personally used "timeMove(int speed, int MS)" since no PID is needed because the goals re-align us. This was 
			made with the intention of saving time. 

			Overall, there are ~4 goals still pending, but they should not be too diffucult to complete. 
			*/
			
			bool descore_corner_goals = true; //If this value is true, it will run the code within the autonomous for descoring the corner goals
											  //If false, then the descoring procedures will not occur 


			//First movement: go forward and intake the ball 
			index(); 
			doubleMove(450, 50, true, 105, 105, 1.3); //used to be 0.9 for the slew rate
			

			//Second movement: turn towards the goal and stop intaking after turning 			
			turn(125, true, 1, true);
			sis();  

			
			

			//Move forward towards the first corner goal
			timeMove(70, 700); //going at a velocity of 70 for 700 MS
			timeMove(40, 480); 
			pros::delay(100); //Some time to rest to prevent bounce? (this works)
			autonASI(); //shoot the ball 


			//Move backwards and turn away
			doubleMove(-300, 50, true, 100, 100, 0.9);
			turn(146, true, 1, true);

			
			//Go forward, turn, and now you're in position for the second goal 
			doubleMove(975, 50, true, 100, 100, 1.3);
			turn(-93, true, 1, true); 
 

			//Go into the second goal and score
			timeMove(45, 950); //need to modify this 
			timeMove(8, 100);
			/*index(); //intaking the balls to descore while in position to shoot
			delay(750);
			sis();*/
			autonASNI();  //NO INDEXING 
			

			//move backwards and turn to face the ball next to the corner goal 
			doubleMove(-200, 50, true, 100, 100, 0.9);
			//descoreFunc();
			turn(87, true, 1, true);


			//Go forward and then go forward once again but slower
			doubleMove(400, 50, true, 105, 105, 1.3);
			index(); 
			doubleMove(600, 50, true, 25, 25, 0.9);
			pros::delay(50); //Give it some time to rest before cutting the indexing 
			sis(); 


			//turn towards the second corner goal and move into it using timeMove
			turn(-35, true, 1, true);
			timeMove(80, 500); //speed of 80 for 500 MS
			timeMove(30, 400);

			index(); //intaking the balls to descore while in position to shoot
			delay(1500);
			sis();
			autonASNI(); //shoot NO INDEX 


			//Move backwards and turn away from the goal and towards the front
			//outake_ball(110, descore_corner_goals); //Outaking the ball while moving backwards
			
			doubleMove(-250, 50, true, 100, 100, 0.9);
			descoreFunc(); //stop the outaking
			turn(127, true, 1, true);
			

			//Go forward, turn, and intake the perimeter ball
			doubleMove(340, 50, true, 100, 100, 1.3);
			turn(-88, true, 1, true);
			index(); 
			timeMove(40, 1220);


			//Move back from the perimeter, turn, and now face the ball in front of the edge goal
			//Move towards that ball
			doubleMove(-310, 50, true, 100, 100, 0.9);
			turn(89, true, 1, true);
			doubleMove(400, 50, true, 100, 100, 1.3);
			doubleMove(450, 50, true, 25, 25, 0.9);
			sis();


			//Turn towards the edge goal, moving forward, and score it 
			turn(-90, true, 1, true); //turn towards the goal
			timeMove(45, 750); //moving towards the fourth goal


			autonASI(); //shoot INDEX 

			
			//Move back from the goal and turn to face forward (same direction as we are standing)
			doubleMove(-350, 50, true, 70, 70, 1.3);

	
			turn(90, true, 1, true);
			
			
			//Move forward and then make a ~45 degree turn towards the last corner goal
			doubleMove(770, 50, true, 100, 100, 1.3);
			turn(-44, true, 1, true);


			//Move forward for the goal, descore, and score
			timeMove(90, 700);
			timeMove(40, 650);
			index(); //intaking the balls to descore while in position to shoot
			delay(1000);
			sis();
			autonASNI(); 
			doubleMove(-350, 50, true, 70, 70, 1.3);

}

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
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */


void opcontrol() {

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
						 
		pros::delay(20);
	}
}
