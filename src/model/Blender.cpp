#include "Blender.h"
#include "../config.h"

Blender::Blender(const BlendPreset* presets, int presetsTotal):
  ampController(
    PIN_VACTROL_0,
    PIN_VACTROL_1,
    PIN_VACTROL_2,
    PIN_VACTROL_3
  ),
  presets(presets),
  presetsTotal(presetsTotal)
{
  setPreset(0);
}

void Blender::setup()
{
  ampController.setup();
  updateAmpController();
}

int Blender::setPreset(int newPresetId)
{
  if(newPresetId >= 0 || newPresetId < presetsTotal)
  {
    presetId = newPresetId;
  }
  for(int i = 0; i < AMPS_TOTAL * KEYFRAMES_TOTAL; i++)
  {
    ampKeyframeValues[i] = presets[presetId].ampKeyframeValues[i];
  }
  updateAmpController();
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
  return presetName(presetId);
}

char const* Blender::presetName(int presetId) const
{
  return presets[presetId].name;
}

float Blender::getKeyframe(int ampId, int keyframe) const
{
  if(ampId < 0 || ampId >= AMPS_TOTAL || keyframe < 0 || keyframe > KEYFRAMES_TOTAL)
    return 0.0;

  int index = (ampId * KEYFRAMES_TOTAL) + keyframe;
  return ampKeyframeValues[index];
}

float const* Blender::getKeyframes() const
{
  return ampKeyframeValues;
}

float Blender::setKeyframe(int ampId, int keyframe, float value)
{
  if(ampId < 0 || ampId >= AMPS_TOTAL || keyframe < 0 || keyframe > KEYFRAMES_TOTAL)
    return 0.0;

  int index = (ampId * KEYFRAMES_TOTAL) + keyframe;
  ampKeyframeValues[index] = value;
  updateAmpController();
  return value;
}

float Blender::setPosition(float newBlendPosition)
{
  if(newBlendPosition < 0)
    newBlendPosition = 0;

  if(newBlendPosition > 1)
    newBlendPosition = 1;

  blendPosition = newBlendPosition;
  updateAmpController();
  return blendPosition;
}

float Blender::getBlendedValue(int ampId) const
{
  return getBlendedValue(ampId, blendPosition);
}

float Blender::getBlendedValue(int ampId, float blend) const
{
  float k1 = getKeyframe(ampId, 0);
  float k2 = getKeyframe(ampId, 1);
  return k1 + blend * (k2 - k1);
}

void Blender::updateAmpController()
{
  for(int i = 0; i < AMPS_TOTAL; i++)
  {
    ampController.setGain(i, getBlendedValue(i));
  }
}
