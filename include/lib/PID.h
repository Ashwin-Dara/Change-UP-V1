#include "main.h"

#ifndef PID_H_
#define PID_H_

class PID{
public:
    float m_kp;
    float m_ki;
    float m_kd;
    int error = 0;
    int prev_error = 0;
    int integral = 0;
    int derivative = 0;
    float power = 0;
    float prev_power = 0;
    bool t_slew_on = true;

    PID(float kp, float ki, float kd){
        m_kp = kp;
        m_ki = ki;
        m_kd = kd;
    }

    float calc (int target, float input, int integralKI, int maxI, int slew, bool m_slew_on){
        prev_power = power;
        prev_error = error;
        error = target - input;

        std::abs(error) < integralKI? integral += error : integral = 0;
        integral >= 0? integral = std::min(integral, maxI) : integral = std::max(integral, -maxI);

        derivative = error - prev_error;

        power = m_kp*error + m_ki*integral + m_kd*derivative;
        
        if(t_slew_on && m_slew_on){
            if (std::abs(power) <= std::abs(prev_power) + std::abs(slew)){
                t_slew_on = false;
            }
            else{
                power = prev_power + slew;
            }
        }

        return power;
    }
};

#endif