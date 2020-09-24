#include "main.h"
#include "../include/lib/robot.h"
#ifndef PID_H
#define PID_H

class PID{
    public: 
        float kP; 
        float kI; 
        float kD;
       
        float kPt; 
        float kIt;
        float kDt; 
        
        int error, lasterror; 
        int pP, iP, dP, slope; 
        int sum, lowbound, highbound; 
        int maxPower, maxSum; 

    virtual void init();
    void setGains(float kPt, float kIt, float kDt);
    int pwr(int sensor, int target);
};

#endif