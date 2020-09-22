#include "main.h"
#include "../include/lib/robot.h"
 
/* 
1) write the basic class in here with all of the functions 
    - functions will include ability to estimate abs position of the robot 
    - modifying the target such that the robot is able to reach the intended pos
        - modify primarily for linear movements (more weighted gains?) 
        - modify secondarily for 2-d movements via profile (less weighted gains?)
2) later on format the code using proper conventions for file management 
3) std::unique_ptr whatever electronics we wish to use for autonomous & the specific motors 
4) inherit the class into the "autoChassis" class that we will be creating later on 
*/ 

/* 
equations: 
position vector = {x, y, theta};

textbook document: 
https://github.com/team914/autolib-pdfs

distance = avg(delta_rE + delta_lE);
x += distance * cos(yaw);
y += distance * sin(yaw);
*/

extern std::shared_ptr rEncoder, lEncoder;
extern std::shared_ptr rightMotor, rightMotor2, leftMotor, leftMotor2;  
extern std::shared_ptr _IMU; 

class Odom {
    private: 
        float avg(float in[], int size){ //bogus//make manual input size 
            for(int i = 0; i < size; i++)
                sum += in[i];
            return (sum/size);
        }

        float radToDeg(float rad){
            return (rad * (180/PI));
        }

        float degToRad(float deg){
            return (deg * (PI/180));
        }

    public: 
        float xPos, yPos, theta = 0.0; 
        void init(){
            xPos = yPos = theta = 0.0; 
        } //sets all var to zero?
        
        void beginPosTracking(){
            float rS = rE->get_rotation();
            float ls = lE->get_rotation();
            pros::delay(20);
            float dR = rE->get_rotation() - rS; 
            float dL = lE->get_rotation() - ls; 
            float s = {dR, dL}; 
            float distance = avg(s, 2);

                theta = gyro->get_yaw();
                xPos += distance*cos(radToDeg(theta));
                yPos += distance*sin(radToDeg(theta)); 
        }

        void magAdjust();
        //

}