#ifndef PID_A_H
#define PID_A_H

class PID{
public:
    float m_kp;
    float m_ki;
    float m_kd;
    int error;
    int prev_error;
    int integral;
    int derivative;

    PID(float kp, float ki, float kd){
        m_kp = kp;
        m_ki = ki;
        m_kd = kd;
    }

    float do (int target, int input, int integralKI, int maxI){
        prev_error = error
        error = target - input

        std::abs(error) < integralKI? integral += error : integral = 0;
        integral >= 0? integral = min(integral, maxI) : integral = max(integral, -maxI)

        derivative = error - prev_error
        return m_kp*error + m_ki*integral + m_kd*derivative
    }
};

#endif