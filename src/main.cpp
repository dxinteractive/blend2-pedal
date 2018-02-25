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
#include "model/BlendPreset.h"
#include "uistate/StateBase.h"
#include "uistate/StateRouteSelector.h"

// inputs
#include <AnalogMultiButton.h>
#include <ResponsiveAnalogRead.h>

static const int BLEND_PRESETS_TOTAL = 7;
static const BlendPreset BLEND_PRESETS[BLEND_PRESETS_TOTAL] = {
  {"Wet", {0, 0, 1, 1, 0, 0, 1, 1}},
  {"Dry", {1, 1, 0, 0, 1, 1, 0, 0}},
  {"Wet send", {1, 1, 0, 1, 1, 1, 1, 1}},
  {"Pan send", {1, 0, 0, 1, 1, 1, 1, 1}},
  {"Pan return", {1, 1, 1, 1, 1, 0, 0, 1}},
  {"Swell send", {0, 0, 0, 1, 0, 0, 1, 1}},
  {"Swell return", {0, 0, 1, 1, 0, 0, 0, 1}}
};

Model model(BLEND_PRESETS, BLEND_PRESETS_TOTAL);
Input input;
View view;

// initial states
const int INITIAL_STATES_TOTAL = 2;
StackuiState* initialStates[INITIAL_STATES_TOTAL] = {
  new StateBase(),
  new StateRouteSelector()
};


Stackui ui(
  model,
  input,
  view,
  initialStates,
  INITIAL_STATES_TOTAL
);

void setup() {
  Serial.begin(9600);
  ui.setup();
}

const int RENDER_FREQUENCY_SHIFT = 3; // 8ms

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
    switch(renderTicks % 4) {
      case 0:
        input.updateButtons();
        break;

      case 1:
        input.updateAnalog0();
        break;

      case 2:
        input.updateAnalog1();
        break;

      case 3:
        model.updateShuffler();
        break;
    }

    ui.renderFrame(ms);
  } else {
    input.updateAnalogExp();
  }

  lastMs = ms;
}
