#include "main.h"
#include "robot.h"
#include "intake.h"

#define BALL_CONSTANT 2700
#define INTAKE_SPEED 127
#define INDEXER_SPEED 127
#define OUTAKE_SPEED 127

void intake_move(float intake_speed){
    lIntake.move(intake_speed);
    rIntake.move(intake_speed);
}

void indexer_move(float index_speed){
    indexer.move(index_speed);
}

void outake_move(float outake_speed){
    
    outake.move(outake_speed);
}


float line_average;
bool aSN = false; //autoShootNoIndex
bool aSI = false; //autoShootIndex
bool manual = false;
int stage = 1;

void autoShootIndex(){
    /*
    while (index_line.get_value() > BALL_CONSTANT){//Shoots First Ball
        indexer.move(INDEXER_SPEED);
        outake.move(OUTAKE_SPEED);
    } 
    indexer.move(0);
    delay(20);
    outake.move(0);
        
    while (index_line.get_value() < BALL_CONSTANT){ //Indexes Next Balll
        indexer.move(INDEXER_SPEED);
    }
    indexer.move(0);
    autoShootOn = false;*/

    //line_average = ((index_bottom.get_value() + index_top.get_value()) / 2);
    line_average = index_bottom.get_value();
    if (stage == 1){//Shooting stage
        if (line_average < BALL_CONSTANT) {//Shoots First Ball
            indexer.move(INDEXER_SPEED);
            outake.move(OUTAKE_SPEED); 
        }
        else{
            indexer.move(0);
            delay(400);
            outake.move(0);
            stage = 2;
        }
    }

    else if (stage == 2){//Indexing Stage
        if(line_average > BALL_CONSTANT){ //Indexes Next Balll
            indexer.move(INDEXER_SPEED);
            outake.move(-OUTAKE_SPEED); 
        }
        else{
            indexer.move(0);
            outake.move(0);
            stage = 1;
            aSI = false;
        }
    }
}

void autoShootNoIndex(){
    line_average = index_bottom.get_value();
    if (line_average < BALL_CONSTANT){//Shoots First Ball
        indexer.move(INDEXER_SPEED);
        outake.move(OUTAKE_SPEED); 
    }
    else{
        indexer.move(0);
        delay(400);
        outake.move(0);
        aSN = false;
    }
}

namespace intake{
    void opcontrol(){
        
        //If in autoShoot mode
        if(!manual){
            //autoShoot
            if (controller.get_digital_new_press(DIGITAL_R1)) {
                aSN = true;
            }
            if (controller.get_digital_new_press(DIGITAL_R2)) {
                aSI = true;
            }

            if(aSN){
                autoShootNoIndex();
            }
            else if(aSI){
                autoShootIndex();
            }

            //Indexing and Outaking
            if(controller.get_digital(DIGITAL_L1)){
                intake_move(127);
                indexer_move(127);
                outake_move(-127);
            }       
            else if(controller.get_digital(DIGITAL_L2)){
                intake_move(-127);
                indexer_move(-127);
                outake_move(-127);
            }
            else if(!aSN && !aSI){ //autoShoot isn't running and no buttons are being pressed, stop the ball manipulating subsytems
                intake_move(0);
                indexer_move(0);
                outake_move(0);
            }

            //Switching to Manual Shooting
            if(controller.get_digital_new_press(DIGITAL_A){
                aSI = false;
                aSN = false;
                stage = 1;
                manual = true;
            }
        }
        else{
            if(controller.get_digital(DIGITAL_L1)){
                intake_move(127);
                indexer_move(127);
                outake_move(-127);
            }       
            else if(controller.get_digital(DIGITAL_L2)){
                intake_move(-127);
                indexer_move(-127);
                outake_move(-127);
            }
            else if(controller.get_digital(DIGITAL_R1)){
                indexer_move(127);
                outake_move(127);
            }
            else{ //if no buttons are pressing then make ALL the motors of the intake stop using motor.stop()
                intake_move(0);
                indexer_move(0);
                outake_move(0);
            }

            //Switching back to autoShoot
            if(controller.get_digital_new_press(DIGITAL_A)){
                aSI = false;
                aSN = false;
                stage = 1;
                manual = false;
            } 
        }

            
    }
}

/* 
1) if there is a ball detected by the line sensor 
    - intake moves alone and picks up more balls
    - indexer stops moving until the line sensor doesn't sense a ball
    rIntake.move(INTAKE_SPEED);
    lIntake.move(INTAKE_SPEED);
    indexer.move(0);

2) if there is no ball detected
    -both the intake and indexer move at the same time until the ball reaches the line sensor
    rIntake.move(INTAKE_SPEED);
    lIntake.move(INTAKE_SPEED);
    indexer.move(INDEXER_SPEED);


*/