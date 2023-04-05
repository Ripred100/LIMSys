#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Button{
  int _PIN;
  int _lastState;
  int _lastRead;
  long _debounceDelay;
  long _lastDebounceTime;

  public:
    Button(int pin, long debounceDelay);
    bool poll();

};

#endif