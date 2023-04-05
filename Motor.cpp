#include "Motor.h"


Motor::Motor(int pwmPin, int dirPin1, int dirPin2) {
  _PIN_PWM = pwmPin;
  _PIN_Dir1 = dirPin1;
  _PIN_Dir2 = dirPin2;
  _isOn = false;
  _PWM = 0;
  _dir = 0;

  pinMode(_PIN_PWM, OUTPUT);
  pinMode(_PIN_Dir1, OUTPUT);
  pinMode(_PIN_Dir2, OUTPUT);
}


void Motor::setPWMCycle(int pwmCycle) {
  _PWM = pwmCycle;
  if(!_isOn) 
    return;
  analogWrite(_PIN_PWM, _PWM);
}

void Motor::setDirection(bool dir) {
  _dir = dir;
  if(!_isOn) 
    return;
  digitalWrite(_PIN_Dir1, _dir);
  digitalWrite(_PIN_Dir2, !_dir);

}

void Motor::turnOn() {
  _isOn = true;
  digitalWrite(_PIN_Dir1, _dir);
  digitalWrite(_PIN_Dir2, !_dir);
  analogWrite(_PIN_PWM, _PWM);
}

void Motor::turnOff() {
  _isOn = false;
  analogWrite(_PIN_PWM, 0);
}

bool Motor::isOn() {
  return _isOn;
}

int Motor::getPWMCycle() {
  //from 0 to 255
  return _PWM;
}

bool Motor::getDirection() {
  //0 is forward, 1 is backward
  return _dir;
}
