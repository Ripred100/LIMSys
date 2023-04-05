#include "Button.h"

Button::Button(int pin, long debounceDelay){
  _PIN = pin;
  _debounceDelay = debounceDelay;
  _lastState = HIGH;
  _lastRead = HIGH;
  _lastDebounceTime = millis();

}

bool Button::poll(){
  int currRead = digitalRead(_PIN);

  //If state changed, reset timer
  if (currRead != _lastRead){
    _lastDebounceTime = millis();
  }
  _lastRead = currRead;

  //If the button hasn't changed in _debounceDelay milliseconds:
  if((millis() - _lastDebounceTime) > _debounceDelay)
  {
    //Check if the new state is different
    if(currRead != _lastState)
    {
      _lastState = currRead;
      if(currRead == LOW){
        return true;
      }
    }


  }
  return false;
  
}
