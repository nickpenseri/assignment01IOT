
#include "TimerOne.h"
#include "initialization.h"
#include "start.h"
#include "game.h"
#include "interrupt.h"

int green_led_pin[] = { FOURTH_GREEN_PIN, THIRD_GREEN_PIN, SECOND_GREEN_PIN, FIRST_GREEN_PIN };
int button_pin[] = { FOURTH_BUTTON_PIN, THIRD_BUTTON_PIN, SECOND_BUTTON_PIN, FIRST_BUTTON_PIN };
bool green_led_state[] = { false, false, false, false };

int fading_Amount;
int brightness;
int count;
volatile state actualState;

void redFading() {
  brightness += fading_Amount;
  analogWrite(RED_PIN, brightness);
  if (brightness == 255 || brightness == 0) {
    fading_Amount = -fading_Amount;
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < LEDS_NUMBER; i++) {
    pinMode(green_led_pin[i], OUTPUT);
    pinMode(button_pin[i], INPUT);
  }
  pinMode(RED_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
  fading_Amount = 5;
  brightness = 0;
  Timer1.initialize(5000);
  Timer1.attachInterrupt(redFading);
  count = 0;
  initializeInterruptStart();
  actualState = START;
  randomSeed(analogRead(0));
}


void loop() {
  switch (actualState) {
    case START:
      Serial.println("Welcome to GMB! Press B1 to Start");
      break;
    case GAME:
      game();
      break;
  }
}
