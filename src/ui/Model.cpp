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

#include "Model.h"

void Model::setup()
{
  blender.setup();
  router.setup();
  shuffler.setup();
}

int Model::getBlendPreset() const
{
  return blender.getPreset();
}

int Model::setBlendPreset(int presetId)
{
  return blender.setPreset(presetId);
}

int Model::nextBlendPreset()
{
  return blender.nextPreset();
}

int Model::prevBlendPreset()
{
  return blender.prevPreset();
}

char const* Model::blendPresetName() const
{
  return blender.presetName();
}

float Model::getBlendKeyframe(int ampId, int keyframe) const
{
  return blender.getKeyframe(ampId, keyframe);
}

float const* Model::getBlendKeyframes() const
{
  return blender.getKeyframes();
}

float Model::setBlendKeyframe(int ampId, int keyframe, float value)
{
  return blender.setKeyframe(ampId, keyframe, value);
}

float Model::setBlendPosition(float blend)
{
  return blender.setPosition(blend);
}

float Model::getBlendedValue(int ampId) const
{
  return blender.getBlendedValue(ampId);
}

float Model::getBlendedValue(int ampId, float blend) const
{
  return blender.getBlendedValue(ampId, blend);
}

int Model::getZPosition() const
{
  return router.getZPosition();
}

int Model::setZPosition(int newZPosition)
{
  return router.setZPosition(newZPosition);
}

int Model::nextZPosition()
{
  return router.nextZPosition();
}

char const* Model::getZPositionLabel() const
{
  return router.getZPositionLabel();
}

char const* Model::getZPositionLabel(int zPosition) const
{
  return router.getZPositionLabel(zPosition);
}

int Model::getDryPosition() const
{
  return router.getDryPosition();
}

int Model::setDryPosition(int newDryPosition)
{
  return router.setDryPosition(newDryPosition);
}

int Model::nextDryPosition()
{
  return router.nextDryPosition();
}

char const* Model::getDryPositionLabel() const
{
  return router.getDryPositionLabel();
}

char const* Model::getDryPositionLabel(int dryPosition) const
{
  return router.getDryPositionLabel(dryPosition);
}

int Model::getPolarityOption() const
{
  return router.getPolarityOption();
}

int Model::setPolarityOption(int newPolarityOption)
{
  return router.setPolarityOption(newPolarityOption);
}

int Model::nextPolarityOption()
{
  return router.nextPolarityOption();
}

char const* Model::getPolarityOptionLabel() const
{
  return router.getPolarityOptionLabel();
}

char const* Model::getPolarityOptionLabel(int polarityOption) const
{
  return router.getPolarityOptionLabel(polarityOption);
}

ShufflerData const* Model::getShufflerData() const
{
  return shuffler.getData();
}

void Model::updateShuffler()
{
  shuffler.update();
  if(shuffler.hasChanged()) {
    StackuiEvent e(EVENT_SHUFFLER, EVENT_SHUFFLER_CHANGED);
    event(e);
  }
}
