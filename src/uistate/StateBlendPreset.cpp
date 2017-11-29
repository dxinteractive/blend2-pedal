/*
 * Blend^2 guitar pedal loop blender and router.
 *
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
*/

#include <Arduino.h>
#include "StateBlendPreset.h"
#include "../ui/Props.h"
#include <Stackui.h>

void StateBlendPreset::render()
{
  PropsPreset props = PropsPreset();
  props.name = "Something";
  renderProps(props);
}

void StateBlendPreset::onEvent(int type, int id, int value)
{
  num++;
  render();
}

void StateBlendPreset::onEvent(int type, int id, float value)
{

}
