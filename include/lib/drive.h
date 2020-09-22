#include "main.h"
#include "../include/lib/PID.h"
#include "../include/lib/robot.h"
#define V_CONST 94.4
#define K 0.01
#define A 0.9
#define C -0.07
#define TOLERANCE_FOR_ERROR 12
#define DRIVE_KP 100
#define DRIVE_KI 100 
#define DRIVE_KD 100 
#ifndef DRIVE_H_
#define DRIVE_H_
//extern pros::Task t1; 

class Drive : PID : PointCorrections{
    protected:
        int16_t currentLinearTarget;
        int16_t currentThetaTarget; 

    public: 
    drive()
    ~drive() = default; 

    void moveTo(int linearMagnitude);
    void turnTo(int degreesToTurn);
    void waitUntilSettled(int toleranceForError = TOLERANCE_FOR_ERROR);
    //overloading
    void waitUntilSettled(int toleranceForError = TOLERANCE_FOR_ERROR, int settleTime);
    void iterate(); 
};

class MotionProfile : Odom {
    private: 
        appendPowerArray();
    
    public: 
    extern vector<int> powersValuesArray; 
    
    void generatePath();
    void appendPowerArray();

}

#endif