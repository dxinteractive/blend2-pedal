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
#include "../config.h"

void StateBase::render(bool top)
{
  passRender();
  PropsBlendLeds props = PropsBlendLeds();
  props.drySend = getModel()->getBlendedValue(AMP_DRY_SEND);
  props.wetSend = getModel()->getBlendedValue(AMP_WET_SEND);
  props.dryReturn = getModel()->getBlendedValue(AMP_DRY_RETURN);
  props.wetReturn = getModel()->getBlendedValue(AMP_WET_RETURN);
  renderProps(props);
}

void StateBase::onEvent(StackuiEvent &e)
{
  if(e.type == EVENT_EXP && e.id == EVENT_EXP_0)
  {
    getModel()->setBlendPosition(e.valueFloat);
    render();
  }

  // if(e.type == EVENT_ANALOG && e.id == EVENT_ANALOG_0)
  // {
  //   Serial.print("a0");
  //   Serial.println(e.valueFloat);
  // }


  passEvent(e);
}

