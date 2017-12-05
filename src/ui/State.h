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

#ifndef STATE_H
#define STATE_H

#include <Stackui.h>
#include "Model.h"

class State: public StackuiState
{
  public:
    State():
      StackuiState() {}

    ~State() {}

  protected:
    Model* getModel() { return static_cast<Model*>(getStackuiModel()); }
};

#endif
