#include "main.h"
#include "../include/lib/robot.h"
#define V_CONST 94.4
#define K 0.01
#define A 0.9
#define C -0.07
#ifdef DRIVE_H_
#define DRIVE_H_

namespace drive{
    float powerSpline(float axisInput);
    void operatorControl();
    
    class autoChassis{
    };
}

#endif