#include "main.h"
#include "../include/lib/Robot.h"
#include "../include/lib/LinearMotionProfile.h"
#include "../include/lib/Drive.h"
using namespace std; 
#define LINEAR_MAX_ACCEL 1.0

class LinearMotionProfile{
  
  public:
  vector<int> powerArray; 
  int16_t desiredPos, desiredTime, desiredVelo; 
  
  LinearMotionProfile() : desiredPos(0), desiredTime(0), desiredVelo(0) {}
  ~LinearMotionProfile() = default; 
  
  void updatePowerArray(int desiredPos, int desiredTime);
  void iterate(); 
  
};
