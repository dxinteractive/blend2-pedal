#ifndef BLENDER_H
#define BLENDER_H

#include <Arduino.h>
#include "BlendPreset.h"
#include "../output/AmpController.h"
#include "../config.h"

class Blender
{
  public:
  	Blender(const BlendPreset* presets, int presetsTotal);

    void setup();

    int getPreset() const { return presetId; }
    int getPresetsTotal() const { return presetsTotal; }
    int setPreset(int newPresetId);
    int nextPreset();
    int prevPreset();
    char const* presetName() const;
    char const* presetName(int presetId) const;

    float getKeyframe(int ampId, int keyframe) const;
    float const* getKeyframes() const;
    float setKeyframe(int ampId, int keyframe, float value);
    float setPosition(float newBlendPosition);
    float getBlendedValue(int ampId) const;
    float getBlendedValue(int ampId, float blend) const;

  private:
    void updateAmpController();

    AmpController ampController;
    const BlendPreset* presets;
    int presetsTotal;
    int presetId;
    float ampKeyframeValues[8];
    float blendPosition;
};

#endif
