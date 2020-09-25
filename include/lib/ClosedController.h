#include "main.h"
#include "../include/lib/robot.h"
#ifndef PID_H
#define PID_H

class PID{
    public: 
        float kPt, kIt, kDt; 
        int error, lasterror, pP, iP, dP, slope, sum; 
        int lowBound, highBound, maxPower, maxSum; 
    virtual void init();
    void setGains(float kPt, float kIt, float kDt);
    int pwr(int sensor, int target);
};

#endif
