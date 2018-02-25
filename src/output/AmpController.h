#ifndef AMPCONTROLLER_H
#define AMPCONTROLLER_H

#include <Arduino.h>

class AmpController
{
  public:
  	AmpController(int pin0, int pin1, int pin2, int pin3);
    void setup();
    void setGain(int pin, float gain);

  private:
  	int pins[4];
  	float gain[4];
};

#endif
