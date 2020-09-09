#include "main.h"
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <cmath>
#ifndef ROBOT_H_
#define ROBOT_H_
#define DRIVE_RT 1 //rightTop Drive
#define DRIVE_RB 2 //rightBottom Drive
#define DRIVE_LT 3 //leftTop Drive
#define DRIVE_LB 4 //leftBottom Drive
#define INTAKE_LEFT 5
#define INTAKE_RIGHT 6
#define INDEXER 7
#define OUTAKE 8

#define IMU_PORT 9
#define LINE_TRACKER_PORT 1
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
void right_move(float speed); 
void left_move(float speed); 
void chas_move(float lspeed, float rspeed);
void reset_encoders();

#endif