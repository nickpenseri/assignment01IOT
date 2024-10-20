#include "interrupt.h"
#include <EnableInterrupt.h>
#include "initialization.h"
#include "game.h"
#include "start.h"
#include "sleepState.h"
extern int buttonPin[];

void initializeInterruptStart() {
  for (int i = 0; i < LEDS_NUMBER; i++) {
    disableInterrupt(buttonPin[i]);
  }
  enableInterrupt(FOURTH_BUTTON_PIN, startGame, RISING);
}

void initializeInterruptGame() {
  disableInterrupt(FOURTH_BUTTON_PIN);
  enableInterrupt(buttonPin[0], pushedFourthButton, RISING);
  enableInterrupt(buttonPin[1], pushedThirdButton, RISING);
  enableInterrupt(buttonPin[2], pushedSecondButton, RISING);
  enableInterrupt(buttonPin[3], pushedFirstButton, RISING);
}

void initializeInterruptSleep() {
  for (int i = 0; i < LEDS_NUMBER; i++) {
    disableInterrupt(buttonPin[i]);
    enableInterrupt(buttonPin[i], wakeUpGame, RISING);
  }
}