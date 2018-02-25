#include "Shuffler.h"
#include <Arduino.h>

void Shuffler::setup()
{
  Wire.begin(8);
}

void Shuffler::update()
{
  changed = false;

  Wire.requestFrom(8, 8);
  if(!Wire.available()) {
    return;
  }

  read(data.selectors[0]);
  read(data.selectors[1]);
  read(data.selectors[2]);
  read(data.selectors[3]);
  read(data.inputSwitch);
  read(data.selector0Z);
  read(data.selector1Z);
  read(data.outputSwitch);
}

void Shuffler::read(int &var)
{
  int data = Wire.read();
  if(data != var)
  {
    var = data;
    changed = true;
  }
}
