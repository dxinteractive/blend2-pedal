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

#ifndef STATE_BLENDSELECTOR_H
#define STATE_BLENDSELECTOR_H

#include <Stackui.h>
#include "../ui/State.h"

class StateBlendSelector: public State
{
  public:
    StateBlendSelector():
      State() {}

    ~StateBlendSelector() {}

    virtual void render();
    virtual void onEvent(StackuiEvent &e);
};

#endif
