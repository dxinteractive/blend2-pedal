#include "Router.h"
#include <Arduino.h>

void Router::setup()
{
  relayController.setup();
  setDryPosition(RelayController::DRY_POSITION_LINEAR);
}

int Router::setZPosition(int newZPosition)
{
  if(newZPosition >= 0 && newZPosition < RelayController::Z_POSITIONS_TOTAL)
  {
    zPosition = newZPosition;
    relayController.setZPosition(newZPosition);
  }
  return zPosition;
}

char const* Router::getZPositionLabel() const
{
  return Router::getZPositionLabel(zPosition);
}

int Router::nextZPosition()
{
  int newZPosition = (zPosition < RelayController::Z_POSITIONS_TOTAL - 1)
    ? zPosition + 1
    : 0;

  return setZPosition(newZPosition);
}

int Router::setDryPosition(int newDryPosition)
{
  if(newDryPosition >= 0 && newDryPosition < RelayController::DRY_POSITIONS_TOTAL)
  {
    dryPosition = newDryPosition;
    relayController.setDryPosition(dryPosition);
  }
  return dryPosition;
}

char const* Router::getDryPositionLabel() const
{
  return Router::getDryPositionLabel(dryPosition);
}

int Router::nextDryPosition()
{
  int newDryPosition = (dryPosition < RelayController::DRY_POSITIONS_TOTAL - 1)
    ? dryPosition + 1
    : 0;

  return setDryPosition(newDryPosition);
}

int Router::setPolarityOption(int newPolarityOption)
{
  if(newPolarityOption >= 0 && newPolarityOption < RelayController::POLARITY_OPTIONS_TOTAL)
  {
    polarityOption = newPolarityOption;
    relayController.setPolarityOption(polarityOption);
  }
  return polarityOption;
}

char const* Router::getPolarityOptionLabel() const
{
  return Router::getPolarityOptionLabel(polarityOption);
}

int Router::nextPolarityOption()
{
  int newPolarityOption = (polarityOption < RelayController::POLARITY_OPTIONS_TOTAL - 1)
    ? polarityOption + 1
    : 0;

  return setPolarityOption(newPolarityOption);
}
