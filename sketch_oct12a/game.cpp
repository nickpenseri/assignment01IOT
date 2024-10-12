#include "game.h"
#include "initialization.h"
#include "Arduino.h"
extern bool green_led_state[];
extern int green_led_pin[];

int getRandomNumber(){
  return random(0,16);
}

void pushButton(int buttonIndex){
  green_led_state[buttonIndex]=!green_led_state[buttonIndex];
  if(green_led_state[buttonIndex]){
    digitalWrite(green_led_pin[buttonIndex],HIGH);
  }else{
    digitalWrite(green_led_pin[buttonIndex],LOW);
  }
}
