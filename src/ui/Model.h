/*
 * Blend^2 guitar pedal loop blender and router.\
 *
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
*/

#ifndef MODEL_H
#define MODEL_H

#include <Stackui.h>

#include "../model/Blender.h"
#include "../model/Router.h"

class Model: public StackuiModel
{
  public:
    Model():
      StackuiModel() {}

    virtual ~Model() {}

    void setup();

    int setBlendPreset(int presetId);
    int nextBlendPreset();
    int prevBlendPreset();
    char const* blendPresetName() const;

    float getBlendKeyframe(int ampId, int keyframe) const;
    float setBlendKeyframe(int ampId, int keyframe, float value);
    float setBlendPosition(float blend);
    float getBlendedValue(int ampId) const;
    float getBlendedValue(int ampId, float blend) const;

    int setZPosition(int newZPosition);
    int nextZPosition();
    char const* getZPositionLabel(int zPosition) const;

    int setDryPosition(int newDryPosition);
    int nextDryPosition();
    char const* getDryPositionLabel(int dryPosition) const;

    int setPhaseOption(int newPhaseOption);
    int nextPhaseOption();
    char const* getPhaseOptionLabel(int phaseOption) const;

  private:
    Blender blender;
    Router router;
};

#endif
