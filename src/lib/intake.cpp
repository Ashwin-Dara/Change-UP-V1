#include "main.h"
#include "robot.h"

#define BALL_CONSTANT 0
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

void intakeIndex_move(float intake_speed, float index_speed){
    lIntake.move(intake_speed);
    rIntake.move(intake_speed);
    indexer.move(index_speed);
}

void opControl(){
    while(1){
        int rIntakeSpeed, lIntakeSpeed, indexerSpeed; 

        if (line.get_value() > BALL_CONSTANT){ //if a ball is detected
            rIntakeSpeed = INTAKE_SPEED; 
            lIntakeSpeed = INTAKE_SPEED; 
            indexerSpeed = 0; 
        }
        else {
            rIntakeSpeed = INTAKE_SPEED; 
            lIntakeSpeed = INTAKE_SPEED; 
            indexerSpeed = INDEXER_SPEED; 
        }

        if(controller.get_digital(DIGITAL_L1)){
            rIntake.move(rIntakeSpeed);
            lIntake.move(lIntakeSpeed);
            indexer.move(indexerSpeed);
        }       
        else { //if no buttons are pressing then make ALL the motors of the intake stop using motor.stop()
            rIntake.stop();
            lIntake.stop();
            indexer.stop();

        }

        if (controller.get_digital_new_press(DIGITAL_R2)) {
            while (line.get_value() > BALL_CONSTANT){
                indexer.move(INDEXER_SPEED);
                outake.move(OUTAKE_SPEED);
                
            } 
            indxer.stop();
            delay(20);
            outake.stop();
        
            while (line.get_value() < BALL_CONSTANT){
                indexer.move(INDEXER_SPEED);
            }
            indexer.stop();
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