/**@file Motor.cpp
 * @author Mathieu Durand
 * @version 1.0.0
 */

#define forward true
#define backward false

#include "Arduino.h"
#include "Motor.h"

/**
 * The speed of the motor (0 - 255)
 */
int Motor::speed() const {
  return speed_m;
}
/**
 * The direction of the motor (true : Forward, false : Backward)
 */
boolean Motor::direction() const {
  return direction_m;
}
/**
 * Contructor of Motor.
 * @param forwardPin : forward pin of the motor (forward direction control)
 * @param backwardPin : backward pin of the motor (backward direction control)
 */
Motor::Motor(const unsigned int forwardPin, const unsigned int backwardPin) {
    forward_pin = forwardPin;
    backward_pin = backwardPin;

    //Set control pins to OUTPUT mode
    pinMode(fPin, OUTPUT);
    pinMode(bPin, OUTPUT);
}

/**
 * Throttle the Motor using integer value between -255 and 255.
 * @param throttle : Integer between -255 and 255 (-255 : 100% backward, 255 : 100% forward).
 */
void Motor::control(int throttle) {
    speed_m = abs(throttle);
    direction_m = throttle > 0;
    updateAll();
}

/**
 * Reverse the Motor direction.
 */
void Motor::reverse() {
    direction_m = !direction_m;
    updateAll();
}

/**
 * Change the Motor direction.
 * @param direction : Boolean representing the new direction (true : Forward, false : Backward)
 */
void Motor::setDirection(boolean direction) {
    direction_m = direction;
    updateAll();
}

/**
 * Change the Motor speed.
 * @param speed : Integer between 0 and 255 (-255 : Slowest, 255 : Fastest).
 */
void Motor::setSpeed(unsigned int speed) {
    speed_m = speed_;
    updateAll();
}

/**
 * Set the real Motor speed and direction
 */
void Motor::updateAll() {
    analogWrite(forward_pin, direction_m ? speed_m : 0.0); //Set to HIGH when going forward and LOW when backward
    analogWrite(backward_pin, direction_m ? 0.0 : speed_m); //Set to HIGH when going backward and LOW when forward
}
