//deleted the line that you had
#ifndef ROBOT_H
#define ROBOT_H
//code 
//#endif (ORIGINAL) (it should be at the end of the file)

extern pros::Controller master(CONTROLLER_MASTER);
extern pros::Motor rightMotorOne;
extern pros::Motor rightMotorTwo;
extern pros::Motor leftMotorOne;
extern pros::Motor leftMotorTwo;
extern pros::Motor intakeOne;
extern pros::Motor intakeTwo;
extern pros::Motor flywheel;

#endif //EDIT: good stuff just the endif goes at the end of the file 
