#include "main.h"
#include "closedLoop.h"
float current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2;
float error = (abs(current_pos) - abs(target));
float sum = 0;
void moveTo(target, speed) {
    while(current_pos != target) {
        int speed = error/5;
        error = (abs(current_pos) - abs(target));
        current_pos = (rDriveB.get_position() + lDriveB.get_position()) / 2;
        while(error > 500) {
            chas.move(100,100);
        }
        while (30 < error < 500) {
            
            chas.move(speed), (speed);
        }
        while(error < 30) {
            sum += error;
            sum *= 0.01;
            if (sum > 10) {
                sum = 10;
            }
            chas.move(speed, + sum, speed + sum);

        }
    }
    chas.move(0,0);
}