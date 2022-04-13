/**@file Motor.h*/

#ifndef HashSerial_h
#define HashSerial_h
#include "Arduino.h"

/**
 Control motors
 */
class Motor {
  public:

    /**
     */
    int speed() const
    boolean direction() const
    
    Motor (const unsigned int forwardPin, const unsigned int backwardPin);
    void control(int throttle);
    void reverse();
    void setDirection(boolean direction);
    void setSpeed(unsigned int speed);

  private:
    unsigned int forward_pin;
    unsigned int backward_pin;
    unsigned int speed_m;
    boolean direction_m;
    void updateAll();
};
#endif
