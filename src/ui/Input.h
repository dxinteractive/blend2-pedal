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

#ifndef INPUT_H
#define INPUT_H

#include <Stackui.h>
#include <AnalogMultiButton.h>
#include <ResponsiveAnalogRead.h>

class Input: public StackuiInput
{
  public:
    Input();
    virtual ~Input() {}

    virtual void setup();
    void updateButtons();
    void updateAnalog0();
    void updateAnalog1();
    void updateAnalogExp();

  private:
    ResponsiveAnalogRead analogExp;
    ResponsiveAnalogRead analog0;
    ResponsiveAnalogRead analog1;
    AnalogMultiButton buttons;
    int buttonsTotal;
    int buttonsAssign[AnalogMultiButton::MAX_BUTTONS];
};

#endif
