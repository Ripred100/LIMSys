#include "globals.h"

volatile long g_encoderTicks = 0;
volatile long g_prevTicks = 0;
volatile long g_prevTime = 0;
volatile float g_prevVelocity = 0;
volatile float g_angularAcceleration = 0;
volatile float g_angularVelocity = 0;