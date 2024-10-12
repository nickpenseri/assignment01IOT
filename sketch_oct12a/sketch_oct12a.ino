
#include "TimerOne.h"
#include "inizialization.h"

int green_led_pin[]={FOURTH_GREEN_PIN,THIRD_GREEN_PIN,SECOND_GREEN_PIN,FIRST_GREEN_PIN}
int button_pin[]={FOURTH_BUTTON_PIN,THIRD_BUTTON_PIN,SECOND_BUTTON_PIN,FIRST_BUTTON_PIN}

int fadingAmount;
int brightness;

void redFading() {
  brightness += fadingAmount;
  if(brightness == 255 || brightness == 0){
    fadingAmount = -fadingAmount;
  }
  analogWrite(RED_PIN, brightness);
}

void setup() {
  for(int i = 0; i < NUMBER_LEDS; i++) {
    pinMode(green_led_pin[i], OUTPUT);
    pinMode(button_pin[i], INPUT);
  }
  pinMode(RED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  fading_amount = 5;
  brightness = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Timer1.initialize(100);
  Timer1.attachInterrupt(redFading);
}
