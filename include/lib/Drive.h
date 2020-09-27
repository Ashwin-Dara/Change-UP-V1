#include "main.h"
#include "../include/lib/PID.h"
#include "../include/lib/robot.h"
#define V_CONST 94.4
#define K 0.01
#define A 0.9
#define C -0.07
#define LINEAR_KP 0.2
#define LINEAR_KI 0
#define LINEAR_KD 0
#define TURN_KP 0.5 //placeholder
#define TURN_KI 0
#define TURN_KD 0
#define INTEGRAL_BOUND 50
#define MAX_INTEGRAL 100
#ifdef DRIVE_H_
#define DRIVE_H_

namespace drive{
    
    /* * * * *  
    @param "axisInput": the joystick value will be entered in the as 
    input for this function, which is a spline function
    
    Function: inside is a generated curve which was made for usercontrol 
    such that for lower inputs the output is not that steep but then it 
    logarithmatically scales

    Similar function to old voltage graphs
    * * * * */

    float powerSpline(float axisInput);
    
    /* * * * *  
    @param "usingSpline": checks for whether or not the spline function will 
    be used or just simple voltage control for tank drive
        @default param = false: back-up if we find that voltage control is pref/sufficient 

    Function: calculates the power that will be assigned to the drive motors 
    and then it will assign the specific power to the motors 

    - use in operator control in main.cpp
    * * * * */

    void operatorControl(bool usingSpine = false);
    
    class autoChassis : public PID {
        //vector representation of targets
        extern int reqPos[2], currentPos[2]; 

        //types of types
        int linearTarget, thetaTarget; 
        ~autoChassis(); 
        virtual void iterate();

    };
}

#endif
