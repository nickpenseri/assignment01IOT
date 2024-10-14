#include "start.h"
#include "TimerOne.h"
#include "initialization.h"
#include "game.h"
#include "Arduino.h"
#include "interrupt.h"

extern state actualState;

int fading_Amount = 5;
int brightness = 0;

void initializeStartState() {
  Timer1.initialize(5000);
  Timer1.attachInterrupt(redFading);
  initializeInterruptStart();
  actualState = START;
}

void redFading() {
  brightness += fading_Amount;
  analogWrite(RED_PIN, brightness);
  if (brightness == 255 || brightness == 0) {
    fading_Amount = -fading_Amount;
  }
}

void startGame(){
  Timer1.stop();
  actualState = GAME;
  initializeGame(readDifficulty());
}



int readDifficulty(){
  int valueRead = analogRead(POTENTIOMETER_PIN);
  int difficulty = map(valueRead, 0, 1023, MIN_DIFFICULTY, MAX_DIFFICULTY);
  return difficulty;
}

