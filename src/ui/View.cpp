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
  //screen.setTextColor(WHITE);
  //screen.setTextSize(2);
  //screen.println("hello :D");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  screen.display();
}

void View::render(StackuiProps &props)
{
  switch(props.getId())
  {
    case PropsBlendSelector::id:
      return render(static_cast<PropsBlendSelector&>(props));

    case PropsRouteSelector::id:
      return render(static_cast<PropsRouteSelector&>(props));
  }
}

void View::render(PropsBlendSelector &props)
{
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setCursor(0,0);
  screen.setTextSize(2);
  screen.println(props.presetName);
  screen.display();
}

void View::render(PropsRouteSelector &props)
{
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setCursor(0,0);
  screen.setTextSize(2);
  screen.println("Relay time");

  screen.setTextSize(1);
  screen.setCursor(0, 56);
  screen.print(props.zPositionLabel);
  // screen.setCursor(41, 56);
  // screen.print(".");
  screen.setCursor(52, 56);
  screen.print(props.polarityOptionLabel);
  // screen.setCursor(80, 56);
  // screen.print(".");
  screen.setCursor(91, 56);
  screen.print(props.dryPositionLabel);

  screen.display();
}
