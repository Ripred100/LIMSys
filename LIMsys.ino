
#include "headers.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
Motor motor1(p_MTR_EN, p_MTR_IN1, p_MTR_IN2);
Button button1(p_BUTTON1, 50);

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
  digitalWrite(p_LED_RED, LOW);
  digitalWrite(p_LED_GREEN, HIGH);
  digitalWrite(p_LED_BLUE, LOW);

  // Set Potentiometer as input
  pinMode(p_POT, INPUT);


  // Set the encoder pin as input
  pinMode(p_ENCODER, INPUT_PULLUP);


  // Attach the encoder to an interrupt
  attachInterrupt(digitalPinToInterrupt(p_ENCODER), updateEncoder, CHANGE);


}


// int test = 0;
// int test2[] = {LOW, LOW, HIGH};

int potRead = 0;
void loop() {

  if(button1.poll())
  {
    // test = test + 1;

    // digitalWrite(p_LED_RED, test2[test%3]);
    // digitalWrite(p_LED_GREEN, test2[(test+1)%3]);
    // digitalWrite(p_LED_BLUE, test2[(test+2)%3]);
    // Serial.println("button Pressed :)");
    if(motor1.isOn()) {
      motor1.turnOff();
    }
    else{
      motor1.turnOn();
    }

    if(motor1.isOn()){
      potRead = analogRead(p_POT);
      motor1.setPWMCycle((map(potRead,0,1023,0,255)));
      Serial.println("pot is at");
      Serial.print(potRead);
    }


  }

    
        

  // if((millis() - g_lastDebounceTime)> debounceDelay)
  // {
  //   Serial.println("button Pressed :)")
  // } 
  // put your main code here, to run repeatedly:
  // motor1.setPWMCycle(200);
  // Serial.println("200");
  // waitABit(3000);
  // motor1.setPWMCycle(100);
  // Serial.println("100");
  // waitABit(3000);
  // motor1.setPWMCycle(50);
  // Serial.println("50");
  // waitABit(3000);
  // motor1.setDirection(!(motor1.getDirection()));
  // Serial.print("Changing direction to: ");
  // waitABit(3000);

}

void waitABit(int time)
{
  unsigned long startTime = millis();
  unsigned long currentTime;
  for(;;)
  {
    currentTime = millis();
    if (currentTime - startTime >= time) {
      return;
  }

}
}

// Function to update the encoder tick count
void updateEncoder() {
g_encoderTicks++;
}