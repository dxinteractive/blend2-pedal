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

class PropsBlendSelector: public StackuiProps
{
  public:
    static const int id = 0;
    virtual int getId() { return PropsBlendSelector::id; }
    char const* presetName;
};

class PropsRouteSelector: public StackuiProps
{
  public:
    static const int id = 1;
    virtual int getId() { return PropsRouteSelector::id; }
    char const* zPositionLabel;
    char const* dryPositionLabel;
    char const* polarityOptionLabel;
};

#endif
