#include "main.h"
#include "../include/lib/robot.h"

/* 
experimenting with new point correction system

logic is that linear movements can essentially be treated as mathematical vectors 
for there is a defined magnitude and theta as our input to move 

if there is any sort of error (difference between where we want to be and 
where we currently are), then we can make the next movement vector
a new vector so that the resultant vector's components is equal to the "point"
that we are trying to be at 

Only concerns are slight issues in final orientation, but that can be easily
resolved by changing our desired orientation

*/

class PointCorrections {
    public: 
    
    float updatedThetaTarget; 
    float updatedLinearTarget; 
    
    int currentXpos; 
    int currentYpos; 
    int desiredXpos; 
    int desiredYpos; 

    PointCorrections() : 
    currentX(0), currentY(0), desiredX(0), desiredY(0) {}

    void correctTheta() { 
        float newTheta = 0;
        int newR = 0; 
        newTheta = ((float) atan((desiredX - currentX)/(desiredY - currentY))) * PI/180;
        newR = (int) sqrt( (pow(desiredX, 2) - pow(currentX, 2)) + (pow(desiredY, 2) - pow(currentY, 2)) );
    }

};