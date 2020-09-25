#include "main.h"
#include "../include/lib/robot.h"
ifndef ODOM_H
#define ODOM_H
/* 
1) write the basic class in here with all of the functions 
    - functions will include ability to estimate abs position of the robot 
    - modifying the target such that the robot is able to reach the intended pos
        - modify primarily for linear movements (more weighted gains?) 
        - modify secondarily for 2-d movements via profile (less weighted gains?)
2) later on format the code using proper conventions for file management 
3) std::unique_ptr whatever electronics we wish to use for autonomous & the specific motors 
4) inherit the class into the "autoChassis" class that we will be creating later on 
*/ 

/* 
equations: 
position vector = {x, y, theta};

textbook document: 


*/

class Odometry{
 private: 
  float dampen(int x); 
  //will dampen the correction gains since with every point update, 
  // while the position of the robot gets more accurate wiht each correct
  // pose becomes more inaccurate the more inaccuracies are corrected
  // with this comes the need to dampen the corrections and ensure that nothing is overpowering
 public: 
  extern int pos[3]; 
  extern int desiredPos[3];
  
  ~Odometry() = default; 
  void init(); //should init the position to 0, 0, 0
  void beginPositionTracking(); //will begin the calculations using the appropriate math
  void stopPositionTracking(); //
  //void pointUpdate(); 
  
};


#endif 
