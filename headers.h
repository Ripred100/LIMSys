#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Motor.h"
#include "Button.h"
#include "globals.h"

void updateEncoder();
void waitABit(int time);

//Motor pins
#define p_MTR_IN1 6
#define p_MTR_IN2 7
#define p_MTR_EN 9

//Encoder pin
#define p_ENCODER 2

//Button Pins
#define p_BUTTON1 4

//LED pins
#define p_LED_RED 10
#define p_LED_GREEN 11
#define p_LED_BLUE 12

//Voltmeter pin
#define p_VOLTMETER A0

//Potentiometer 
#define p_POT A1

//Temperature sencors
#define p_TEMPERATURE1 A3
#define p_TEMPERATURE2 A4
#define p_TEMPERATURE3 A5