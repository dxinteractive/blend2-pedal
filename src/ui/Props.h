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

#ifndef PROPS_H
#define PROPS_H

#include <Stackui.h>

class PropsPreset: public StackuiProps
{
  public:
    static const int id = 0;
    virtual int getId() { return PropsPreset::id; }
    char const* name;
};

#endif
