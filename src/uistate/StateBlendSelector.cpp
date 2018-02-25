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
#include "StateBlendSelector.h"
#include "StateRouteSelector.h"
#include "../ui/State.h"
#include "../ui/Props.h"
#include "../config.h"

void StateBlendSelector::render(bool top)
{
  passRender();
  if(top)
  {
    PropsBlendSelector props = PropsBlendSelector();
    props.presetName = getModel()->blendPresetName();
    props.ampKeyframeValues = getModel()->getBlendKeyframes();
    renderProps(props);
  }
}

void StateBlendSelector::onEvent(StackuiEvent &e)
{
  if(e.type == EVENT_BUTTON)
  {
    if(e.id == EVENT_BUTTON_UP && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      StateRouteSelector* newState = new StateRouteSelector();
      replaceState(newState);
      return;
    }
    if(e.id == EVENT_BUTTON_LEFT &&
      (e.valueInt == EVENT_BUTTON_VALUE_PRESS || e.valueInt == EVENT_BUTTON_VALUE_REPEAT)
    )
    {
      getModel()->prevBlendPreset();
      render(true);
      return;
    }
    if(e.id == EVENT_BUTTON_RIGHT &&
      (e.valueInt == EVENT_BUTTON_VALUE_PRESS || e.valueInt == EVENT_BUTTON_VALUE_REPEAT)
    )
    {
      getModel()->nextBlendPreset();
      render(true);
      return;
    }
    return;
  }
  passEvent(e);
}
