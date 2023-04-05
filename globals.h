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

//Temperature sensor globals
extern float g_sensorValue1;
extern float g_temperatureC1;
extern float g_sensorValue2;
extern float g_temperatureC2;
extern float g_sensorValue3;
extern float g_temperatureC3;

//Voltage sensor variables
extern float g_voltage_val;
extern float g_voltage;
extern float g_R1;
extern float g_R2;

//Button Globals
extern int g_lastButtonState;
#endif