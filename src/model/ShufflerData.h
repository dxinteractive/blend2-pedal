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

#ifndef SHUFFLERDATA_H
#define SHUFFLERDATA_H

class ShufflerData
{
  public:
    int selectors[4]; // 0 A, 1 B, 2 C, 3 D, 4 bypass, 5 bypass
    int selector0Z; // 0 normal, 1 Z loop in use
    int selector1Z; // 0 normal, 1 Z loop in use
    int inputSwitch; // 0 off, 1 on
    int outputSwitch; // 0 normal, 1 F loop is in front, 2 off
};

#endif
