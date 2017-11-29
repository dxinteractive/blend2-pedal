#ifndef ROUTER_H
#define ROUTER_H

#include <Arduino.h>
#include "../output/RelayController.h"
#include "../config.h"

class Router
{
  public:
    static char const* getZPositionLabel(int zPosition)
    {
      static char const* arr[] = {
        "None",
        "Dry",
        "Wet",
        "DMM"
      };
      return arr[zPosition];
    }

    static char const* getDryPositionLabel(int dryPosition)
    {
      static char const* arr[] = {
        "Branched",
        "Linear"
      };
      return arr[dryPosition];
    }

    static char const* getPhaseOptionLabel(int phaseOption)
    {
      static char const* arr[] = {
        "Phase Normal",
        "Phase Inverted"
      };
      return arr[phaseOption];
    }

  	Router():
      relayController(
        PIN_RELAY_0,
        PIN_RELAY_1,
        PIN_RELAY_2,
        PIN_RELAY_3,
        PIN_RELAY_4
      ) {}

    void setup();

    int setZPosition(int newZPosition);
    int nextZPosition();

    int setDryPosition(int newDryPosition);
    int nextDryPosition();

    int setPhaseOption(int newPhaseOption);
    int nextPhaseOption();

  private:
    RelayController relayController;

    int zPosition;
    int dryPosition;
    int phaseOption;
};

#endif
