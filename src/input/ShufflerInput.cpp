#include "ShufflerInput.h"
#include <Arduino.h>

void ShufflerInput::setup()
{
  Wire.begin();
}

void ShufflerInput::update()
{
  Wire.requestFrom(8, 8);
  if(Wire.available()) {
    selector1 = Wire.read();
  }
  if(Wire.available()) {
    selector2 = Wire.read();
  }
  if(Wire.available()) {
    selector3 = Wire.read();
  }
  if(Wire.available()) {
    selector4 = Wire.read();
  }
  if(Wire.available()) {
    inputSwitch = Wire.read();
  }
  if(Wire.available()) {
    selector1Z = Wire.read();
  }
  if(Wire.available()) {
    selector2Z = Wire.read();
  }
  if(Wire.available()) {
    outputSwitch = Wire.read();
  }
}
