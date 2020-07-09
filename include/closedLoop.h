#include "main.h"
#ifndef CLOSEDLOOP_H
#define CLOSEDLOOP_H
float current_pos;
float target;
float error;
void chas_move(float lspeed, float rspeed){
    lDriveT.move(lspeed);
    lDriveB.move(lspeed);
    rDriveT.move(rspeed);
    rDriveB.move(rspeed);
}



#endif