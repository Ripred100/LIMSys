#include "globals.h"

volatile long g_encoderTicks = 0;
volatile long g_prevTicks = 0;
volatile long g_prevTime = 0;
volatile float g_prevVelocity = 0;
volatile float g_angularAcceleration = 0;
volatile float g_angularVelocity = 0;

float g_sensorValue1 = 0.0;
float g_temperatureC1 = 0.0;
float g_sensorValue2 = 0.0;
float g_temperatureC2 = 0.0;
float g_sensorValue3 = 0.0;
float g_temperatureC3 = 0.0;

float g_voltage_val=0;
float g_voltage=0;
float g_R1=30000;
float g_R2=7560;

int g_lastButtonState = HIGH;