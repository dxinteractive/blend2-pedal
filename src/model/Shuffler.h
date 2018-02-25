#ifndef SHUFFLER_H
#define SHUFFLER_H

#include <Arduino.h>
#include <Wire.h>
#include "./ShufflerData.h"

class Shuffler
{
  public:
    void setup();
    void update();
    bool hasChanged() const { return changed; }
    ShufflerData const* getData() const { return &data; }

  private:
    void read(int &var);

    ShufflerData data;
    bool changed;
};

#endif
