#ifndef BLENDER_H
#define BLENDER_H

#include <Arduino.h>
#include "../output/AmpController.h"
#include "../config.h"

class Blender
{
  public:
    static const int AMPS_TOTAL = 4;
    static const int KEYFRAMES_TOTAL = 2;

  	Blender():
      ampController(
        PIN_VACTROL_0,
        PIN_VACTROL_1,
        PIN_VACTROL_2,
        PIN_VACTROL_3
      ) {}

    void setup();

    int getPreset() const { return presetId; }
    int setPreset(int newPresetId);
    int nextPreset();
    int prevPreset();
    char const* presetName() const;

    float getKeyframe(int ampId, int keyframe) const;
    float setKeyframe(int ampId, int keyframe, float value);
    float setPosition(float newBlendPosition);
    float getBlendedValue(int ampId) const;
    float getBlendedValue(int ampId, float blend) const;

  private:
    AmpController ampController;
    int presetId;
    int presetsTotal;
    float ampKeyframeValues[8];
    float blendPosition;
};

#endif
