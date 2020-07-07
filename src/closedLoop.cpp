#include "closedLoop.h"


void chas_move(float lspeed, float rspeed){
    lDriveT.move(lspeed);
    lDriveB.move(lspeed);
    rDriveT.move(rspeed);
    rDriveB.move(rspeed);
}
int error;
float current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2;
int speed;
int closeboost = 0;
int sum;

void loopmove (int distance){

    rDriveB.set_zero_position(0);
    lDriveB.set_zero_position(0);

    while (distance > current_pos) {

        error = (distance - current_pos);

        if (error < 30){
            sum = sum + error;
            closeboost = sum * 0.01;
            
        }
        else{
            speed = (error/distance)*100;
        }
    chas_move (speed + closeboost, speed + closeboost);
       

    pros::delay(10);

    }

    chas_move(0,0);
    
}

void autonomous (void){

    loopmove (1000);


}

