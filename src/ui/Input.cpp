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

#include "Input.h"
#include <Stackui.h>
#include "../config.h"

Input::Input():
  StackuiInput(),
  analogExp(PIN_ANALOG_EXP, false),
  analog0(PIN_ANALOG_0, true),
  analog1(PIN_ANALOG_1, true),
  buttons(
    PIN_BUTTONS,
    BUTTONS_TOTAL,
    BUTTONS_VALUES
  ),
  buttonsTotal(BUTTONS_TOTAL)
{
  for(int i = 0; i < buttonsTotal; i++)
    this->buttonsAssign[i] = BUTTONS_ASSIGN[i];
}

void Input::setup()
{
  analog0.setSnapMultiplier(0.001);
  analog1.setSnapMultiplier(0.001);
  analogExp.setSnapMultiplier(0.001);
}

void Input::updateButtons()
{
  buttons.update();
  for(int i = 0; i < buttonsTotal; i++)
  {
    if(buttons.onPress(i))
    {
      StackuiEvent e(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_VALUE_PRESS);
      event(e);
    }

    if(buttons.onRelease(i))
    {
      StackuiEvent e(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_VALUE_RELEASE);
      event(e);
    }

    if(buttons.onPressAfter(i, 500, 250))
    {
      StackuiEvent e(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_VALUE_REPEAT);
      event(e);
    }

    if(buttons.onReleaseBefore(i, 1000))
    {
      StackuiEvent e(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_VALUE_TAP);
      event(e);
    }

    if(buttons.onPressAfter(i, 1000))
    {
      StackuiEvent e(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_VALUE_HOLD);
      event(e);
    }
  }
}

void Input::updateAnalog0()
{
  analog0.update();
  if(analog0.hasChanged())
  {
    float value = analog0.getSmoothValue() / 1023.0;
    StackuiEvent e(EVENT_ANALOG, EVENT_ANALOG_0, 1.0 - value);
    event(e);
  }
}

void Input::updateAnalog1()
{
  analog1.update();
  if(analog1.hasChanged())
  {
    float value = analog1.getSmoothValue() / 1023.0;
    StackuiEvent e(EVENT_ANALOG, EVENT_ANALOG_1, value);
    event(e);
  }
}

void Input::updateAnalogExp()
{
  analogExp.update();
  if(analogExp.hasChanged())
  {
    float value = analogExp.getSmoothValue() / 1023.0;
    StackuiEvent e(EVENT_EXP, EVENT_EXP_0, value);
    event(e);
  }
}
