#include "game.h"
#include "initialization.h"
#include "Arduino.h"
#include "interrupt.h"
#include "start.h"
#include "output.h"

extern bool greenLedState[];
extern int greenLedPin[];
extern int buttonPin[];
int actualNumber;
int score;
int difficultyChosen;
double diffFactor;
extern state actualState;

long maxTime;
long lastFirstPress;
long lastSecondPress;
long lastThirdPress;
long lastFourthPress;

int getRandomNumber() {
  return random(0, 16);
}

void pushButton(int buttonIndex) {
  greenLedState[buttonIndex] = !greenLedState[buttonIndex];
  if (greenLedState[buttonIndex]) {
    digitalWrite(greenLedPin[buttonIndex], HIGH);
  } else {
    digitalWrite(greenLedPin[buttonIndex], LOW);
  }
}

void pushedFirstButton() {
  long ts = millis();
  if (ts - lastFirstPress > DEBOUNCE_TIME) {
    pushButton(3);
    lastFirstPress = ts;
  }
}

void pushedSecondButton() {
  long ts = millis();
  if (ts - lastSecondPress > DEBOUNCE_TIME) {
    pushButton(2);
    lastSecondPress = ts;
  }
}

void pushedThirdButton() {
  long ts = millis();
  if (ts - lastThirdPress > DEBOUNCE_TIME) {
    pushButton(1);
    lastThirdPress = ts;
  }
}

void pushedFourthButton() {
  long ts = millis();
  if (ts - lastFourthPress > DEBOUNCE_TIME) {
    pushButton(0);
    lastFourthPress = ts;
  }
}

void initializeGame(int difficulty) {
  
  difficultyChosen = difficulty;
  diffFactor = BASE_FACTOR - (difficulty * 0.10);
  lastFirstPress = millis();
  lastSecondPress = millis();
  lastThirdPress = millis();
  lastFourthPress = millis();
  turnOffLeds();
  initializeInterruptGame();
  
  score = 0;
  maxTime = FIRST_ROUND_TIME;
}

void gameRound() {
  actualNumber = random(0, 16);
  clearOutput();
  writeMessage("Go!! ");
  delay(1000);
  Serial.println( "Difficoltà scelta: "+String(difficultyChosen));
  setNextLine();
  writeMessage("Extracted number: " + String(actualNumber));

  delay(maxTime);
  if (checkCorrectGuess()) {
    score += SCORE_INCREASE;
    clearOutput();
    writeMessage("GOOD! Score:" + String(score));
    delay(2000);
    maxTime *= diffFactor;
    turnOffLeds();
  } else {
    turnOffLeds();
    endGame();
  }
}

void endGame() {
  digitalWrite(RED_PIN, HIGH);
  delay(1000);
  digitalWrite(RED_PIN, LOW);
  clearOutput();
  writeMessage("Game Over ");
  setNextLine();
  writeMessage("Final Score: " + String(score));
  delay(10000);
  actualState = START;
  turnOffLeds();
  initializeStartState();
}

bool checkCorrectGuess() {
  int guess = 0;
  noInterrupts();
  for (int i = 0; i < LEDS_NUMBER; i++) {
    guess += greenLedState[i] ? (1 << ((LEDS_NUMBER-1) - i)) : 0;
  }
  interrupts();
  Serial.println(guess);
  return guess == actualNumber;
}

void turnOffLeds() {
  for (int i = 0; i < LEDS_NUMBER; i++) {
    greenLedState[i] = false;
    digitalWrite(greenLedPin[i], LOW);
  }
}
