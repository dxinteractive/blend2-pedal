#include "Blender.h"

void Blender::setup()
{
  ampController.setup();
}

int Blender::setPreset(int newPresetId)
{
  if(newPresetId >= 0 || newPresetId < presetsTotal)
  {
    presetId = newPresetId;
  }
  return presetId;
}

int Blender::nextPreset()
{
  int newPresetId = (presetId < presetsTotal - 1)
    ? presetId + 1
    : 0;

  return setPreset(newPresetId);
}

int Blender::prevPreset()
{
  int newPresetId = (presetId > 0)
    ? presetId - 1
    : presetsTotal - 1;

  return setPreset(newPresetId);
}

char const* Blender::presetName() const
{
  return "???";
}

float Blender::getKeyframe(int ampId, int keyframe) const
{
  if(ampId < 0 || ampId >= AMPS_TOTAL || keyframe < 0 || keyframe > KEYFRAMES_TOTAL)
    return 0.0;

  int index = (ampId * KEYFRAMES_TOTAL) + keyframe;
  return ampKeyframeValues[index];
}

float Blender::setKeyframe(int ampId, int keyframe, float value)
{
  if(ampId < 0 || ampId >= AMPS_TOTAL || keyframe < 0 || keyframe > KEYFRAMES_TOTAL)
    return 0.0;

  int index = (ampId * KEYFRAMES_TOTAL) + keyframe;
  ampKeyframeValues[index] = value;
  return value;
}

float Blender::setPosition(float newBlendPosition)
{
  if(newBlendPosition < 0)
    newBlendPosition = 0;

  if(newBlendPosition > 1)
    newBlendPosition = 1;

  blendPosition = newBlendPosition;
  return blendPosition;
}

float Blender::getBlendedValue(int ampId) const
{
  return getBlendedValue(ampId, blendPosition);
}

float Blender::getBlendedValue(int ampId, float blend) const
{
  // TODO BLENDING!!!
  return 0.1;
}
