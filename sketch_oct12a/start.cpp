#include "start.h"
#include "TimerOne.h"
#include "initialization.h"
extern state actualState;

void startGame(){
  Timer1.stop();
  actualState = GAME;
}
