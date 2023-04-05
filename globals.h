#ifndef GLOBALS_H
#define GLOBALS_H

//Encoder Globals
extern volatile long g_encoderTicks;
extern volatile long prevTicks;
extern volatile long prevTime;
extern volatile float prevVelocity;
extern volatile float angularAcceleration;
extern volatile float angularVelocity;

#endif