#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

class LedController
{
  public:
    static const int LED_UP = 0;
    static const int LED_DOWN = 1;
    static const int LED_LEFT = 2;
    static const int LED_RIGHT = 3;

  	LedController(int pin0, int pin1, int pin2, int pin3);
    void setup();
    void setBrightness(int pin, float brightness);

  private:
  	int pins[4];
  	float brightness[4];
};

#endif
