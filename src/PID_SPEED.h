#ifndef PID_SPEED_H
#define PID_SPEED_H

class PID_SPEED {
public:
  double throttle;
  double throttle_min;
  double throttle_target;
  double steering_factor;

  PID_SPEED();

  virtual ~PID_SPEED();

  void Init(double min, double target, double sf);
  void UpdateThrottle(double steering_angle);
};

#endif /* PID_SPEED_H */
