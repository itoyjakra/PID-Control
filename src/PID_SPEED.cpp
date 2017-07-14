#include "PID_SPEED.h"
#include <iostream>
#include "math.h"

using namespace std;

PID_SPEED::PID_SPEED() 
{
    throttle = 0.0;
}

PID_SPEED::~PID_SPEED() {}

void PID_SPEED::Init(double min, double target, double sf) 
{
    throttle_min = min;
    throttle_target = target;
    steering_factor = sf;
}

void PID_SPEED::UpdateThrottle(double steering_angle)
{
    throttle = throttle_target - steering_factor * fabs(steering_angle);
    if (throttle < throttle_min) throttle = throttle_min;
}
