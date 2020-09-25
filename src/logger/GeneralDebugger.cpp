#include "main.h"
#include <string>

class Llemu{
  public:
    static bool heaviside; 
    static int lineNumberCount; 
  
    static void init(){
      lineNumberCount = 0; 
      pros::lcd::initialize(); 
    }
    
    static void debugDrive(const Drive &drive){
    //debug the chassis, PID, autonomous, intake, uptake
    }
    
    static void debugAutonomous(const Drive &drive);
    //show the error, position, power, and etc.
    
    static void debugIntake(const Intake &intake); 
    //display the true velocity of each component of the subsystem
     

};
