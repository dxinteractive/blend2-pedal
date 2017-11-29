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
}

int Model::setBlendPreset(int presetId)
{
  return 123;
}

int Model::nextBlendPreset()
{
  return 123;
}

int Model::prevBlendPreset()
{
  return 123;
}

char const* Model::blendPresetName() const
{
  return "???";
}

float Model::getBlendKeyframe(int ampId, int keyframe) const
{
  return 0.5;
}

float Model::setBlendKeyframe(int ampId, int keyframe, float value)
{
  return 0.5;
}

float Model::setBlendPosition(float blend)
{
  return 0.5;
}

float Model::getBlendedValue(int ampId) const
{
  return 0.5;
}

float Model::getBlendedValue(int ampId, float blend) const
{
  return 0.5;
}

int Model::setZPosition(int newZPosition)
{
  return router.setZPosition(newZPosition);
}

int Model::nextZPosition()
{
  return router.nextZPosition();
}

char const* Model::getZPositionLabel(int zPosition) const
{
  return router.getZPositionLabel(zPosition);
}

int Model::setDryPosition(int newDryPosition)
{
  return router.setDryPosition(newDryPosition);
}

int Model::nextDryPosition()
{
  return router.nextDryPosition();
}

char const* Model::getDryPositionLabel(int dryPosition) const
{
  return router.getDryPositionLabel(dryPosition);
}

int Model::setPhaseOption(int newPhaseOption)
{
  return router.setPhaseOption(newPhaseOption);
}

int Model::nextPhaseOption()
{
  return router.nextPhaseOption();
}

char const* Model::getPhaseOptionLabel(int phaseOption) const
{
  return router.getPhaseOptionLabel(phaseOption);
}
