#include "start.h"
#include "TimerOne.h"
#include "initialization.h"
#include "game.h"
#include "Arduino.h"
#include "interrupt.h"
#include "output.h"

extern state actualState;
extern long startTime;

int fading_Amount = 5;
int brightness = 0;

void initializeStartState() {
  startTime = millis();
  Timer1.initialize(10000);
  Timer1.attachInterrupt(redFading);
  initializeInterruptStart();
  actualState = START;
  clearOutput();
  writeMessage("Welcome to GMB!");
  setNextLine();
  writeMessage("Press B1 to Start");
}

void redFading() {
  brightness += fading_Amount;
  analogWrite(RED_PIN, brightness);
  if (brightness == 250 || brightness == 0) {
    fading_Amount = -fading_Amount;
  }
}

void startGame(){
  Timer1.stop();
  actualState = GAME;
  delay(1000);
  initializeGame(readDifficulty());
}

int mapDiffculty(int potValue){

  if (potValue >= 0 && potValue < 256) {
    Serial.println("Difficoltà 1");
    return 1;
  } else if (potValue >= 256 && potValue < 512) {
    Serial.println("Difficoltà 2");
    return 2;
  } else if (potValue >= 512 && potValue < 768) {
    Serial.println("Difficoltà 3");
    return 3;
  } else if (potValue >= 768 && potValue <= 1023) {
    Serial.println("Difficoltà 4");
    return 4;
  }

}
int readDifficulty(){
  int valueRead = analogRead(POTENTIOMETER_PIN);
  int difficulty = mapDiffculty(valueRead);
  return difficulty;
}

