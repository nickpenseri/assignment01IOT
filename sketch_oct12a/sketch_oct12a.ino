
#include "TimerOne.h"
#include "inizialization.h"

int led_pin[]={FOURTH_GREEN_PIN,THIRD_GREEN_PIN,SECOND_GREEN_PIN,FIRST_GREEN_PIN}
int button_pin[]={FOURTH_BUTTON_PIN,THIRD_BUTTON_PIN,SECOND_BUTTON_PIN,FIRST_BUTTON_PIN}

void setup() {

  pinMode(13, OUTPUT);      
  pinMode(BUTTON_PIN, INPUT);     
  Serial.begin(9600)
}

void loop() {
  // put your main code here, to run repeatedly:

}
