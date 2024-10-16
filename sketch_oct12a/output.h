#ifndef OUTPUT_H
#define OUTPUT_H
#include "Arduino.h"

void outputInit();
void writeMessage(String message);
void setNextLine();
void resetCursor();
void clearOutput();
#endif
