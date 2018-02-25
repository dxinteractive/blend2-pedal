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

#ifndef STATE_BASE_H
#define STATE_BASE_H

#include <Stackui.h>
#include "../ui/State.h"

class StateBase: public State
{
  public:
    StateBase():
      State() {}

    ~StateBase() {}

    virtual void render(bool top = true);
    virtual void onEvent(StackuiEvent &e);
};

#endif
