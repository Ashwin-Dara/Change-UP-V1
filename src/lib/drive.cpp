#include "main.h"
#include "../include/lib/PID.h"
#include "../include/lib/drive.h"

Drive::Drive(){ 
    currentLinearTarget = currentThetaTarget = 0; 
    useSlew = headerCorrect = false; 
    currentXpos = currentYpos = 0; 
}

Drive::~Drive() = default; 

void Drive::move(int linearMag, int theta){
    
    currentThetaTarget += theta; 
    currentLinearTarget = linearMag; 

    desiredXpos = linearMag * cos(theta);
    desiredYpos = linearMag * sin(theta);
}

void waitUntilSettled(int toleranceForError = TOLERANCE_FOR_ERROR){
    while(1){
        if( abs(pwr( rE->get_value(), currentLinearTarget)) < 2 && abs(error) < toleranceForError){
            break; 
        }   
    }
}

void waitUntilSettled(int toleranceForError = TOLERANCE_FOR_ERROR, int settleTime){
    int timer = 0; 
    while(1){
        timer += 30; 
        if( abs(pwr( rE->get_value(), currentLinearTarget)) < 2 && abs(error) < toleranceForError){
            break; 
        }
        if(timer >= settleTime){
            timer = 0;
            break; 
        }   
        pros::delay(30);
    }
}

void iterate(){
    bool newTask = true;
    int currentPower; 
    if(newTask) currentPower = 0; 
    int requestedPIDpower = pwr(rE->get_value, currentLinearTarget);
    int deltaPower = requestedPIDpower - currentPower; 
    if( abs(deltaPower) > SLEW_RATE ) currentPower += sgn(deltaPower) * 5; 
    else currentPower = requestedPIDpower; 
    
    


}

//void waitUntilSettled(int toleranceForError)

