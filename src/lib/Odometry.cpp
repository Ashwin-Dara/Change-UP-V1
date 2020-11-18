#include "main.h"
#include "../include/odom.h"
using namespace std; 

Odometry::~Odometry() = default; 

void Odometry::init() {
  for(int index = 0; index < 3; index++){
    pos[index] = 0;
  }
}

void beignPositionTracking() { 
  
}
