#ifndef SHUFFLERINPUT_H
#define SHUFFLERINPUT_H

#include <Arduino.h>
#include <Wire.h>

class ShufflerInput
{
  public:
    void setup();
    void update();

  private:
    int selector1; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
    int selector2; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
    int selector3; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
    int selector4; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
    int selector1Z; // 0 normal, 1 Z loop in use
    int selector2Z; // 0 normal, 1 Z loop in use
    int inputSwitch; // 0 off, 1 on
    int outputSwitch; // 0 normal, 1 F loop is in front, 2 off
};

#endif
