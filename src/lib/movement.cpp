#include "main.h"
#include "robot.h"
#include "PID.h"
#include "movement.h"
#define STRAIGHT_KP 0.39
#define STRAIGHT_KI 0.15
#define STRAIGHT_KD 0.0
#define TURN_KP 1.8
#define TURN_KI 0.38
#define TURN_KD 0.0
#define INTEGRAL_KICK_IN 50
#define MAX_INTEGRAL 25

#define COUNT_CONST 28

void move(int target, bool ask_slew, int slew_rate){
    PID straight(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

    float voltage;
    float encoder_average;

    float imu_offset;
    float heading;
    int count = 0;

    reset_encoders();
    imu_offset = imu.get_rotation();
    while(true){
        
        encoder_average = (rDriveT.get_position() + lDriveT.get_position()) / 2;
        voltage = straight.calc(target, encoder_average, INTEGRAL_KICK_IN, MAX_INTEGRAL, slew_rate, ask_slew);

        heading = imu.get_rotation() - imu_offset;

        chas_move(voltage - heading, voltage + heading); // (voltage + heading, voltage - heading)
        printf("error: %f\r\n", (550 - ((rDriveT.get_position() + lDriveT.get_position()) / 2)));
        if (abs(target - encoder_average) <= 3) count++;
        if (count >= COUNT_CONST) break;

        delay(10);
    }
    
    chas_move(0,0);
    printf("count: %d\r\n", (count));
}

void turn(int target, bool ask_slew, int slew_rate){
    PID rotate(TURN_KP, TURN_KI, TURN_KD);

    float voltage;
    float position;
    int count = 0;
    float imu_start;

    imu_start = imu.get_rotation();

    while(true){
        position = imu.get_rotation() - imu_start;
        voltage = rotate.calc(target, position, INTEGRAL_KICK_IN, MAX_INTEGRAL, slew_rate, ask_slew);

        chas_move(voltage, -voltage);
        printf("error: %f\r\n", (imu.get_rotation()));
        if (abs(target - position) <= 1.5) count++;
        if (count >= COUNT_CONST) break;

        delay(10);
    }

    chas_move(0,0);
    printf("count: %d\r\n", (count));
}