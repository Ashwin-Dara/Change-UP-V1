#include "main.h"


/*in robot.cpp
void chas_move(float lspeed, float rspeed){
    lDriveT.move(lspeed);
    lDriveB.move(lspeed);
    rDriveT.move(rspeed);
    rDriveB.move(rspeed);
}*/



void moveTo(int target, int speed){
    float current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2; // to find average of both encoders
    while(current_pos != target){
        while(current_pos < target){
            current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2;
            chas_move(speed, speed);
            delay(10);  
        }

        while(current_pos > target){
            current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2;
            chas_move(-speed, -speed);
            delay(10);
        }
    }
    
    
    
    chas_move(0,0);
    

    //I forgot to check for the negative target case, can you do it?
    
    
}

/*in main.cpp
void autonomous() {
    moveTo(-2000, -100) //move 2000 units back at 100 speed
}