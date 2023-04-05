
#include "headers.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
Motor motor1(p_MTR_EN, p_MTR_IN1, p_MTR_IN2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();

  pinMode(p_BUTTON1, INPUT);

  // Set the RGB LED pins as output
  pinMode(p_LED_RED, OUTPUT);
  pinMode(p_LED_GREEN, OUTPUT);
  pinMode(p_LED_BLUE, OUTPUT);

    //Set LED to Red until button pressed
  digitalWrite(p_LED_RED, HIGH);
  digitalWrite(p_LED_GREEN, LOW);
  digitalWrite(p_LED_BLUE, LOW);

    // Set the encoder pin as input
  pinMode(p_ENCODER, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(p_ENCODER), updateEncoder, CHANGE);

  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.setPWMCycle(200);
  delay(3000);
  motor1.setPWMCycle(100);
  delay(3000);
  motor1.setPWMCycle(50);
  delay(3000);
  motor1.setDirection(!(motor1.getDirection()));
  delay(3000);

}

// Function to update the encoder tick count
void updateEncoder() {
g_encoderTicks++;
}