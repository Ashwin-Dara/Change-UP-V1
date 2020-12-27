#include "main.h"
#include "../include/odom.h"
using namespace std; 

Odometry::~Odometry() = default; 

void Odometry::init() {
  for(int index = 0; index < 3; index++){
    pos[index] = 0;
  }
}

void Odometry::beginPositionTracking() { 
  //delta n = n_initial - n_final
  double theta = IMU.get_yaw(); //getting theta_initial - should start at 0 
  double rWheelPos = rm1.get_position(); 
  double lWheelPos = lm1.get_position(); 
  
  //waiting 25 ms for the "delta" to be significant
  pros::delay(25); 
  
  double deltaTheta = IMU.get_yaw() - theta; //delta = initial - final
  double deltaR = rm1.get_position() - rWheelPos; 
  double deltaL = lm1.get_position() - lWheelPos;
  // delta S = (r + l)/2
  double deltaS = (deltaR + deltaL)/2; 
  
  //now using the odometry equation to update position after getting variables
  //reference: Princeton COS495 Lecture
  pos[X] += deltaS * cos(theta + deltaTheta/2); 
  pos[Y] += deltaS * sin(theta + deltaTheta/2); 
}

void Odometry::logger() {
  
}
