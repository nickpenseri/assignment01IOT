#include "game.h"
#include "initialization.h"
#include "Arduino.h"
#include "interrupt.h"

extern bool green_led_state[];
extern int green_led_pin[];
extern int button_pin[];
int actualNumber;
int score;

long lastFirstPress;
long lastSecondPress;
long lastThirdPress;
long lastFourthPress;

extern state actualState;
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
void pushedFirstButton()
{
  long ts = millis();
  if (ts - lastFirstPress > DEBOUNCE_TIME)
  {
    pushButton(3);
    lastFirstPress = ts; 
  }
}
void pushedSecondButton()
{
  long ts = millis();
  if (ts - lastSecondPress > DEBOUNCE_TIME)
  {
    pushButton(2);
    lastSecondPress = ts;
  }
}

void pushedThirdButton()
{
  long ts = millis();
  if (ts - lastThirdPress > DEBOUNCE_TIME)
  {
    pushButton(1);
    lastThirdPress = ts;
  }
}

void pushedFourthButton()
{
  long ts = millis();
  if (ts - lastFourthPress > DEBOUNCE_TIME)
  {
    pushButton(0);
    lastFourthPress = ts;
  }
}
void initializeGame() {
  lastFirstPress = millis();
  lastSecondPress = millis();
  lastThirdPress = millis();
  lastFourthPress = millis();
  for(int i = 0; i < LEDS_NUMBER; i++) {
    digitalWrite(green_led_pin[i], LOW);
    green_led_state[i] = false;
  }
  initializeInterruptGame();
  score = 0;
}
void game(){
  initializeGame();
  actualState=SLEEP;
}


