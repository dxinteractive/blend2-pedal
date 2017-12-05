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
        "Z:None",
        "Z:Dry",
        "Z:Wet",
        "Z:DMM"
      };
      return arr[zPosition];
    }

    static char const* getDryPositionLabel(int dryPosition)
    {
      static char const* arr[] = {
        "Split",
        "Linear"
      };
      return arr[dryPosition];
    }

    static char const* getPolarityOptionLabel(int polarityOption)
    {
      static char const* arr[] = {
        "P:+1",
        "P:-1"
      };
      return arr[polarityOption];
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

    int getZPosition() const { return zPosition; }
    char const* getZPositionLabel() const;
    int setZPosition(int newZPosition);
    int nextZPosition();

    int getDryPosition() const { return dryPosition; }
    char const* getDryPositionLabel() const;
    int setDryPosition(int newDryPosition);
    int nextDryPosition();

    int getPolarityOption() const { return polarityOption; }
    char const* getPolarityOptionLabel() const;
    int setPolarityOption(int newPolarityOption);
    int nextPolarityOption();

  private:
    RelayController relayController;

    int zPosition;
    int dryPosition;
    int polarityOption;
};

#endif
