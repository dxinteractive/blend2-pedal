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
#include "StateRouteSelector.h"
#include "StateBlendSelector.h"
#include "../ui/State.h"
#include "../ui/Props.h"
#include "../config.h"

void StateRouteSelector::render()
{
  PropsRouteSelector props = PropsRouteSelector();
  props.zPositionLabel = getModel()->getZPositionLabel();
  props.dryPositionLabel = getModel()->getDryPositionLabel();
  props.polarityOptionLabel = getModel()->getPolarityOptionLabel();
  renderProps(props);
}

void StateRouteSelector::onEvent(StackuiEvent &e)
{
  if(e.type == EVENT_BUTTON)
  {
    if(e.id == EVENT_BUTTON_UP && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      StateBlendSelector* newState = new StateBlendSelector();
      replaceState(newState);
      return;
    }
    if(e.id == EVENT_BUTTON_LEFT && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      getModel()->nextZPosition();
      render();
      return;
    }
    if(e.id == EVENT_BUTTON_DOWN && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      getModel()->nextPolarityOption();
      render();
      return;
    }
    if(e.id == EVENT_BUTTON_RIGHT && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      getModel()->nextDryPosition();
      render();
      return;
    }
    return;
  }

  passEvent(e);
}
