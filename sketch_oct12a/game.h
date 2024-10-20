#ifndef GAME_H
#define GAME_H

/*
returns a random number for each game round
*/
int getRandomNumber();

/*
change the state of led related to button pressed
*/
void pushButton(int buttonIndex);
void pushedFirstButton();
void pushedSecondButton();
void pushedThirdButton();
void pushedFourthButton();

/*
manages the game round  
*/
void gameRound();

/*
initializes the start of game
*/
void initializeGame(int difficulty);

/*
checks if the guessed number is equal to the one extracted
*/
bool checkCorrectGuess();

/*
turns off all the green leds
*/
void turnOffLeds();

/*
manages the end game in case of defeat
*/
void endGame();
#endif
