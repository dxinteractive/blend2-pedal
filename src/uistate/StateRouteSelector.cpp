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

void StateRouteSelector::render(bool top)
{
  passRender();
  if(top)
  {
    PropsRouteSelector props = PropsRouteSelector();
    props.zPosition = getModel()->getZPosition();
    props.dryPosition = getModel()->getDryPosition();
    props.zPositionLabel = getModel()->getZPositionLabel();
    props.dryPositionLabel = getModel()->getDryPositionLabel();
    props.polarityOptionLabel = getModel()->getPolarityOptionLabel();
    props.shufflerData = getModel()->getShufflerData();
    renderProps(props);
  }
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
      render(true);
      return;
    }
    if(e.id == EVENT_BUTTON_DOWN && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      getModel()->nextPolarityOption();
      render(true);
      return;
    }
    if(e.id == EVENT_BUTTON_RIGHT && e.valueInt == EVENT_BUTTON_VALUE_PRESS)
    {
      getModel()->nextDryPosition();
      render(true);
      return;
    }
    return;
  }

  if(e.type == EVENT_SHUFFLER)
  {
    render(true);
    return;
  }

  passEvent(e);
}
