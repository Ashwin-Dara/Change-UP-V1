#include "main.h"
#include "../include/lib/robot.h"
#ifdef DRIVE_H_
#define DRIVE_H_

namespace drive{
    float powerSpline(float axisInput);
    void operatorControl();
    
    struct autoInitializer{
        int16_t setPointR, setPointL; 
        int16_t modAdjust; 
        int16_t thetaAdjust; 
        int16_t phaseAdjust; 
    } chassisConstruct;

    class autoChassis{

    };
}

#endif