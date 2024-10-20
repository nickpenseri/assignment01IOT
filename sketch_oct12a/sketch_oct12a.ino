/*developed by Alex Frisoni, Nicolo Penserini, Lukasz Wojnicz*/
#include "TimerOne.h"
#include "initialization.h"
#include "start.h"
#include "game.h"
#include "interrupt.h"
#include "output.h"
#include "sleepState.h"

int greenLedPin[] = { FOURTH_GREEN_PIN, THIRD_GREEN_PIN, SECOND_GREEN_PIN, FIRST_GREEN_PIN };
int buttonPin[] = { FOURTH_BUTTON_PIN, THIRD_BUTTON_PIN, SECOND_BUTTON_PIN, FIRST_BUTTON_PIN };
bool greenLedState[] = { false, false, false, false };


long startTime;
volatile state actualState;



void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LEDS_NUMBER; i++) {
    pinMode(greenLedPin[i], OUTPUT);
    pinMode(buttonPin[i], INPUT);
  }
  pinMode(RED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  randomSeed(analogRead(0));
  outputInit();
  initializeStartState();
}


void loop() {
  switch (actualState) {
    case START:
      if(millis() - startTime >= STANDBY_TIME) {
        sleepGame();
      }
      break;
    case GAME:
      gameRound();
      break;
  }
}
