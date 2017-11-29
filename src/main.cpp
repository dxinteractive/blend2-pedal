/*
 * Blend^2 guitar pedal loop blender and router.
 * Main program file
 *
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
*/

#include <Arduino.h>
#include <Wire.h>

// ui
#include <Stackui.h>
#include "ui/Model.h"
#include "ui/Input.h"
#include "ui/View.h"
#include "uistate/StateBlendPreset.h"

// inputs
#include <AnalogMultiButton.h>
#include <ResponsiveAnalogRead.h>

Model model;
Input input;
View view;

Stackui ui(
  model,
  input,
  view,
  new StateBlendPreset()
);

void setup() {
  Serial.begin(9600);
  model.setup();
  input.setup();
  view.setup();
}

const int RENDER_FREQUENCY_SHIFT = 5; // 32ms

unsigned long ms;
unsigned long lastMs;

void loop() {
  ms = millis();
  if(ms <= lastMs) {
    return;
  }

  ui.update(ms);

  unsigned long renderTicks = ms >> RENDER_FREQUENCY_SHIFT;
  if(renderTicks > lastMs >> RENDER_FREQUENCY_SHIFT) {
    switch(renderTicks % 3) {
      case 0:
        input.updateButtons();
        break;

      case 1:
        input.updateAnalog0();
        break;

      case 2:
        input.updateAnalog1();
        break;
    }

    ui.renderFrame(ms);
  } else {
    input.updateAnalogExp();
  }

  lastMs = ms;
}
