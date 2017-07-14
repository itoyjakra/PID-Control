#include "PID.h"
#include <iostream>

using namespace std;

PID::PID() 
{
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd, double sf, double sc)
{
    Kp = kp;
    Ki = ki;
    Kd = kd;
    speed_factor = sf;
    speed_cutoff = sc;
}

void PID::UpdateError(double cte) 
{
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::GetSteeringValue(double speed)
{
    double steer_value = - Kp * p_error - Ki * i_error - Kd * d_error;
    if (speed > speed_cutoff) steer_value = steer_value * speed_factor / speed;

    return steer_value;
}
