#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <Arduino.h>

class LedController
{
  public:
  	LedController(int pin0, int pin1, int pin2, int pin3);
    void setup();
    void setBrightness(int pin, float brightness);

  private:
  	int pins[4];
  	float brightness[4];
};

#endif
