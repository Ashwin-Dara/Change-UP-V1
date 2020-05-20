#include "main.h"
#include "../include/lib/PID.h"
#define KPL 50
#define KIL 1
#define KDL 5
extern PID liftPid; 

namespace lift{
    extern int target; 
    void liftPresets();
    void operatorControl();


}