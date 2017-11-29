#include "AmpController.h"
#include <Arduino.h>

AmpController::AmpController(int pin0, int pin1, int pin2, int pin3)
{
  pins[0] = pin0;
  pins[1] = pin1;
  pins[2] = pin2;
  pins[3] = pin3;
}

void AmpController::setup()
{
  pinMode(pins[0], OUTPUT);
  pinMode(pins[1], OUTPUT);
  pinMode(pins[2], OUTPUT);
  pinMode(pins[3], OUTPUT);
  analogWriteFrequency(pins[0], 36000);
  analogWriteFrequency(pins[1], 36000);
  analogWriteFrequency(pins[2], 36000);
  analogWriteFrequency(pins[3], 36000);
  analogWrite(pins[0], 0);
  analogWrite(pins[1], 0);
  analogWrite(pins[2], 0);
  analogWrite(pins[3], 0);
}

void AmpController::setGain(int pin, float gain)
{
  this->gain[pin] = gain;
  analogWrite(pins[pin], gain * 255);
}
