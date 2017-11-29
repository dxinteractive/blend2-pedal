#include "Router.h"

void Router::setup()
{
  relayController.setup();
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

int Router::nextDryPosition()
{
  int newDryPosition = (dryPosition < RelayController::DRY_POSITIONS_TOTAL - 1)
    ? dryPosition + 1
    : 0;

  return setDryPosition(newDryPosition);
}

int Router::setPhaseOption(int newPhaseOption)
{
  if(newPhaseOption >= 0 && newPhaseOption < RelayController::PHASE_OPTIONS_TOTAL)
  {
    phaseOption = newPhaseOption;
    relayController.setPhaseOption(phaseOption);
  }
  return phaseOption;
}

int Router::nextPhaseOption()
{
  int newPhaseOption = (phaseOption < RelayController::PHASE_OPTIONS_TOTAL - 1)
    ? phaseOption + 1
    : 0;

  return setPhaseOption(newPhaseOption);
}
