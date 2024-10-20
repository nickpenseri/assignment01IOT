#include "sleepState.h"
#include "initialization.h"
#include "interrupt.h"
#include "TimerOne.h"
#include "start.h"
#include <avr/sleep.h>

extern state actualState;

void wakeUpGame() {

}

void sleepGame() {
  actualState = SLEEP;
  Timer1.stop();
  initializeInterruptSleep();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  sleep_disable();
  Serial.println("Svegliato");
  actualState = START;
  initializeStartState();
}

