#include "interrupt.h"
#include <EnableInterrupt.h>
#include "initialization.h"
#include "game.h"
#include "start.h"
#include "sleepState.h"
extern int button_pin[];

void initializeInterruptStart() {
  for (int i = 0; i < LEDS_NUMBER; i++) {
    disableInterrupt(button_pin[i]);
  }
  enableInterrupt(FOURTH_BUTTON_PIN, startGame, RISING);
}

void initializeInterruptGame() {
  disableInterrupt(FOURTH_BUTTON_PIN);
  enableInterrupt(button_pin[0], pushedFourthButton, RISING);
  enableInterrupt(button_pin[1], pushedThirdButton, RISING);
  enableInterrupt(button_pin[2], pushedSecondButton, RISING);
  enableInterrupt(button_pin[3], pushedFirstButton, RISING);
}

void initializeInterruptSleep() {
  for (int i = 0; i < LEDS_NUMBER; i++) {
    disableInterrupt(button_pin[i]);
    enableInterrupt(button_pin[i], wakeUpGame, RISING);
  }
}
