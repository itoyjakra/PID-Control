#include "PID.h"
#include <iostream>
#include <uWS/uWS.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
{
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) 
{
    Kp = kp;
    Ki = ki;
    Kd = kd;
    std::cout << " K values in init: " << Kp << " " << Ki << " " << Kd << std::endl;
}

void PID::UpdateError(double cte) 
{
    i_error += cte;
    d_error = cte - p_error;
    p_error = cte;
}

double PID::TotalError() {
}

void PID::Restart(uWS::WebSocket<uWS::SERVER> ws)
{
    std::string reset_msg = "42[\"reset\",{}]";
    ws.send(reset_msg.data(), reset_msg.length(), uWS::OpCode::TEXT);
}
