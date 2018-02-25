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
#include "./model/ShufflerData.h"

class PropsBlendSelector: public StackuiProps
{
  public:
    static const int id = 0;
    virtual int getId() { return PropsBlendSelector::id; }
    char const* presetName;
    float const* ampKeyframeValues;
};

class PropsBlendGraph: public StackuiProps
{
  public:
    static const int id = 1;
    virtual int getId() { return PropsBlendGraph::id; }
    char const* presetName;
    bool selected = false;
    float start;
    float end;
};

class PropsRouteSelector: public StackuiProps
{
  public:
    static const int id = 2;
    virtual int getId() { return PropsRouteSelector::id; }
    int zPosition;
    int dryPosition;
    char const* zPositionLabel;
    char const* dryPositionLabel;
    char const* polarityOptionLabel;
    ShufflerData const* shufflerData;
};

class PropsRouteLetter: public StackuiProps
{
  public:
    static const int id = 4;
    virtual int getId() { return PropsRouteLetter::id; }
    char letter;
};

class PropsBlendLeds: public StackuiProps
{
  public:
    static const int id = 5;
    virtual int getId() { return PropsBlendLeds::id; }
    float drySend;
    float wetSend;
    float dryReturn;
    float wetReturn;
};

#endif
