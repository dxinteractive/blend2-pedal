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

#include "View.h"
#include <Stackui.h>
#include <Arduino.h>
#include "Props.h"

void View::setup()
{
  ledController.setup();

  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setTextSize(2);
  screen.println("hello :D");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  screen.display();
}

void View::render(StackuiProps &props)
{
  switch(props.getId())
  {
    case PropsPreset::id:
      return render(static_cast<PropsPreset&>(props));
  }
}

void View::render(PropsPreset &props)
{
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setCursor(0,0);
  screen.setTextSize(1);
  screen.println(props.name);
  screen.display();
}
