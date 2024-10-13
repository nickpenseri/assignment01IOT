#include "interrupt.h"
#include <EnableInterrupt.h>
#include "initialization.h"
#include "game.h"
#include "start.h"
extern int button_pin[];

void initializeInterruptStart(){
  enableInterrupt(FOURTH_BUTTON_PIN, startGame, RISING);
}
void initializeInterruptGame(){
  disableInterrupt(FOURTH_BUTTON_PIN);
  enableInterrupt(button_pin[0], pushedFourthButton, RISING);
  enableInterrupt(button_pin[1], pushedThirdButton, RISING);
  enableInterrupt(button_pin[2], pushedSecondButton, RISING);
  enableInterrupt(button_pin[3], pushedFirstButton, RISING);
}

