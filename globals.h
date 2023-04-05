#ifndef GLOBALS_H
#define GLOBALS_H
#include "Arduino.h"

//Encoder Globals
extern volatile long g_encoderTicks;
extern volatile long g_prevTicks;
extern volatile long g_prevTime;
extern volatile float g_prevVelocity;
extern volatile float g_angularAcceleration;
extern volatile float g_angularVelocity;

//Button Globals
extern int g_lastButtonState;
#endif