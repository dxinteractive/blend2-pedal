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
#include <Stackui.h>
#include "StateBase.h"
#include "../ui/State.h"
#include "../ui/Props.h"

void StateBase::render()
{

}

void StateBase::onEvent(StackuiEvent &e)
{
  Serial.println(">>>");
  passEvent(e);
}
