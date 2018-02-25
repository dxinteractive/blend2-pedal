#include "RelayController.h"
#include <Arduino.h>

void RelayController::setup()
{
  pinMode(pinDryAfter, OUTPUT);
  pinMode(pinDryZ, OUTPUT);
  pinMode(pinWetZ, OUTPUT);
  pinMode(pinDmmZ, OUTPUT);
  pinMode(pinPolarityFlip, OUTPUT);
  digitalWrite(pinDryAfter, LOW);
  digitalWrite(pinDryZ, LOW);
  digitalWrite(pinWetZ, LOW);
  digitalWrite(pinDmmZ, LOW);
  digitalWrite(pinPolarityFlip, LOW);
}

void RelayController::setZPosition(int newZPosition)
{
  digitalWrite(pinDryZ, LOW);
  digitalWrite(pinWetZ, LOW);
  digitalWrite(pinDmmZ, LOW);

  switch(newZPosition)
  {
    case RelayController::Z_POSITION_DRY:
      digitalWrite(pinDryZ, HIGH);
      break;

    case RelayController::Z_POSITION_WET:
      digitalWrite(pinWetZ, HIGH);
      break;

    case RelayController::Z_POSITION_DMM:
      digitalWrite(pinDmmZ, HIGH);
      break;
  }
}

void RelayController::setDryPosition(int newDryPosition)
{
  digitalWrite(pinDryAfter, newDryPosition ? HIGH : LOW);
}

void RelayController::setPolarityOption(int newPolarityOption)
{
  digitalWrite(pinPolarityFlip, newPolarityOption ? HIGH : LOW);
}
