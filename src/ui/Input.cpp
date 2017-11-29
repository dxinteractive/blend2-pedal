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
  shufflerInput.setup();
}

void Input::updateButtons()
{
  buttons.update();
  for(int i = 0; i < buttonsTotal; i++)
  {
    if(buttons.onPress(i))
      event(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_PRESS);

    if(buttons.onRelease(i))
      event(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_RELEASE);

    if(buttons.onPressAfter(i, 500, 500))
      event(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_REPEAT);

    if(buttons.onReleaseBefore(i, 1000))
      event(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_TAP);

    if(buttons.onPressAfter(i, 1000))
      event(EVENT_BUTTON, buttonsAssign[i], EVENT_BUTTON_HOLD);
  }
}

void Input::updateAnalog0()
{
  analog0.update();
}

void Input::updateAnalog1()
{
  analog1.update();
}

void Input::updateAnalogExp()
{
  analogExp.update();
}
