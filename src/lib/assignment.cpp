#include "main.h"
#include "drive.h"

/*in robot.cpp

void chas_move(float lspeed, float rspeed){
    lDriveT.move(lspeed);
    lDriveB.move(lspeed);
    rDriveT.move(rspeed);
    rDriveB.move(rspeed);
}*/

int current_pos = rDriveB.get_position() + lDriveB.get_position() / 2; // to find average of both encoders

int target_speed = 99.5

void moveTo(int target, int speed){
    chas_move(target_speed);
    if (std::abs(target)/target = 1){//checks that the target is positive
        while(current_pos < target){
            delay(10);
        }
    }
    //I forgot to check for the negative target case, can you do it?
    
    chas_move(0, 0);
}

/*in main.cpp

void autonomous() {
    moveTo(-2000, -100) //move 2000 units back at 100 speed
}


