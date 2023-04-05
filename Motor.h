#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {

  int _PIN_PWM;
  int _PIN_Dir1;
  int _PIN_Dir2;
  bool _isOn;
  int _PWM;
  bool _dir;

  public:
    Motor(int pwmPin, int dirPin1, int dirPin2);
    void setPWMCycle(int pwmCycle);
    void setDirection(bool dir);
    void turnOn();
    void turnOff();
    bool isOn();
    int getPWMCycle();
    bool getDirection();
};

#endif