#ifndef AMPCONTROLLER_H
#define AMPCONTROLLER_H

#include <Arduino.h>

class AmpController
{
  public:
    static const int AMP_DRY_SEND = 0;
    static const int AMP_WET_SEND = 1;
    static const int AMP_DRY_RETURN = 2;
    static const int AMP_WET_RETURN = 3;

  	AmpController(int pin0, int pin1, int pin2, int pin3);
    void setup();
    void setGain(int pin, float gain);

  private:
  	int pins[4];
  	float gain[4];
};

#endif
