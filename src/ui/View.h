/*
 * Blend^2 guitar pedal loop blender and router.\
 *
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
*/

#ifndef VIEW_H
#define VIEW_H

#include <Stackui.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Props.h"
#include "../output/LedController.h"
#include "../config.h"

class View: public StackuiView
{
  public:
    View():
      StackuiView(),
      ledController(
        PIN_LED_UP,
        PIN_LED_DOWN,
        PIN_LED_LEFT,
        PIN_LED_RIGHT
      ),
      screen(
        PIN_SID,
        PIN_SCLK,
        PIN_DC,
        PIN_RST,
        PIN_CS
      ) {}

    virtual ~View() {}

    void setup();
    virtual void render(StackuiProps &props);

    void render(PropsPreset &props);

  private:
    LedController ledController;
    Adafruit_SSD1306 screen;
};

#endif
