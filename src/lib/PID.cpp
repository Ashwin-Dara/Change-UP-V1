#include "main.h"
#include "../include/lib/PID.h"

void PID::init(){
    kPt = kIt = kDt = error = lasterror = pP = 0; 
    iP = dP = slope = sum = lowBound  = highBound = maxPower = 0; 
}
void PID::setGains(float kPt, float kIt, float kDt){
    this->kPt = kPt; 
    this->kIt = kIt; 
    this->kDt = kDt; 
}
int PID::pwr(int sensor, int target){
    lasterror = error; 
    error = target - sensor; 
    pP = error * kPt; 
    if(std::abs(error) > lowBound && std::abs(error) < highBound)
        if(std::abs(sum) < maxSum) sum = (sum+error);
    else sum = 0; 
    iP = sum * kIt; 
    slope = error - lasterror; 
    dP = slope * kDt;
    int power = pP + iP + dP; 
    power = (std::abs(error) > maxPower)?(sgn(maxPower) * maxPower):power; 
    return power; 
}

