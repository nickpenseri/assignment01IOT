#include "start.h"
#include "initialization.h"
#include "TimerOne.h"

#include <EnableInterrupt.h>
extern state actualState;
void initializeInterrupt(){
  enableInterrupt(FOURTH_BUTTON_PIN, startGame, RISING);
}
void startGame(){
  Timer1.stop();
  actualState = GAME;
  disableInterrupt(FOURTH_BUTTON_PIN);
}

