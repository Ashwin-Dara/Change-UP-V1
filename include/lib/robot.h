#include "main.h"
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <cmath>
#ifndef ROBOT_H_
#define ROBOT_H_
#define DRIVE_RT 18 //rightTop Drive
#define DRIVE_RB 12 //rightBottom Drive
#define DRIVE_LT 17 //leftTop Drive
#define DRIVE_LB 16 //leftBottom Drive
#define INTAKE_LEFT 15
#define INTAKE_RIGHT 8
#define INDEXER 11
#define OUTAKE 13

#define IMU_PORT 9
#define INDEX_BOTTOM_LINE_PORT 2
#define INDEX_TOP_LINE_PORT 4
using namespace pros; 

//single driver (primary joystick)
extern Controller controller;

/*
 * Drive Configuration:  
 * 4 motor drive 200RPM 
 * 
 * one motor on each side are elevated, two in total 
 * are elevated
 * the other motors are not 
 * 
 * "T" after the name clarifies the motor as being "top" or the 
 * elevated motor
*/

extern Motor rDriveT; 
extern Motor rDriveB;
extern Motor lDriveT;
extern Motor lDriveB;  
extern Motor lIntake;
extern Motor rIntake;
extern Motor indexer;
extern Motor outake;
extern ADIAnalogIn index_bottom;
extern ADIAnalogIn index_top;
extern Imu imu;
void right_move(float speed); 
void left_move(float speed); 
void chas_move(float lspeed, float rspeed);
void reset_encoders();

#endif