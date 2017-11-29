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

#ifndef STATE_BLEND_PRESET_H
#define STATE_BLEND_PRESET_H

#include <Stackui.h>

class StateBlendPreset: public StackuiState
{
  public:
    StateBlendPreset():
      StackuiState() {}

    ~StateBlendPreset() {}

    virtual void render();

    virtual void onEvent(int type, int id, int value);
    virtual void onEvent(int type, int id, float value);

  private:
    int num = 0;
};

#endif
