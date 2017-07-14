#ifndef PID_H
#define PID_H

class PID {
public:
  double p_error;
  double i_error;
  double d_error;

  double Kp;
  double Ki;
  double Kd;

  double speed_factor;
  double speed_cutoff;

  PID();

  virtual ~PID();

  void Init(double kp, double ki, double kd, double sf, double sc);

  void UpdateError(double cte);

  double GetSteeringValue(double speed);
};

#endif /* PID_H */
