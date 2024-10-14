#ifndef GAME_H
#define GAME_H

int getRandomNumber();
void pushButton(int buttonIndex);
void pushedFirstButton();
void pushedSecondButton();
void pushedThirdButton();
void pushedFourthButton();
void gameRound();
void initializeGame(int difficulty);
bool checkCorrectGuess();
void turnOffLeds();
void endGame();
#endif
