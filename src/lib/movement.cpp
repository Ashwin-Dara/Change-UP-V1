#include "main.h"
#include "robot.h"
#include "PID.h"
#include "movement.h"
#define STRAIGHT_KP 0.2
#define STRAIGHT_KI 0
#define STRAIGHT_KD 0
#define TURN_KP 0
#define TURN_KI 0
#define TURN_KD 0
#define INTEGRAL_KICK_IN 50
#define MAX_INTEGRAL 100

void move(int target, bool ask_slew, int slew_rate){
    PID straight(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

    float voltage;
    float encoder_average;

    float imu_offset;
    float heading;
    int count;

    reset_encoders();
    //imu_offset = imu.get_yaw();

    while(true){
        
        encoder_average = (rDriveB.get_position() + lDriveB.get_position()) / 2;
        voltage = straight.calc(target, encoder_average, INTEGRAL_KICK_IN, MAX_INTEGRAL, slew_rate, ask_slew);

        //heading = imu.get_yaw(); - imu_offset;

        chas_move(voltage, voltage); // (voltage + heading, voltage - heading)

        if (abs(target) - abs(encoder_average) <= 5) count++;
        if (count >= 5) break;

        delay(10);
    }

    chas_move(0,0);
}

/*void turn(int target, bool ask_slew, int slew_rate){
    PID rotate(TURN_KP, TURN_KI, TURN_KD);

    float voltage;
    float position;
    int count;

    float imu_start = imu.get_yaw();

    while(true){
        position = imu.get_yaw() - imu_start;
        voltage = rotate.calc(target, position, INTEGRAL_KICK_IN, MAX_INTEGRAL, slew_rate, ask_slew);

        chas_move(-voltage, voltage);

        if (abs(target) - abs(position) <= 5) count++;
        if (count >= 5) break;

        delay(10);
    }

    chas_move(0,0);
}*/