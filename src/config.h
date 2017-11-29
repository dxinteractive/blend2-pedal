/*
 * Blend^2 guitar pedal loop blender and router.
 * Configuration file
 *
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
*/

#ifndef CONFIG_H
#define CONFIG_H

 // pins
const int PIN_RELAY_0 = 0;
const int PIN_RELAY_1 = 1;
const int PIN_RELAY_2 = 2;
const int PIN_VACTROL_0 = 3;
const int PIN_VACTROL_1 = 4;
const int PIN_VACTROL_2 = 5;
const int PIN_VACTROL_3 = 6;
const int PIN_SID = 7;
const int PIN_SCLK = 8;
const int PIN_DC = 9;
const int PIN_RST = 10;
const int PIN_CS = 11;
const int PIN_RELAY_3 = 12;
const int PIN_RELAY_4 = 13;
const int PIN_ANALOG_EXP = A0;
const int PIN_ANALOG_1 = A1;
const int PIN_ANALOG_0 = A2;
const int PIN_BUTTONS = A3;
const int PIN_I2C_SDA = 18;
const int PIN_I2C_SCL = 19;
const int PIN_LED_DOWN = 20;
const int PIN_LED_RIGHT = 21;
const int PIN_LED_LEFT = 22;
const int PIN_LED_UP = 23;

const int BUTTONS_TOTAL = 4;
const int BUTTONS_VALUES[BUTTONS_TOTAL] = {0, 256, 512, 768};
const int BUTTONS_ASSIGN[BUTTONS_TOTAL] = {0, 2, 1, 3};

const int EVENT_BUTTON = 0;
const int EVENT_ANALOG = 1;
const int EVENT_EXP = 2;

const int EVENT_BUTTON_PRESS = 0;
const int EVENT_BUTTON_RELEASE = 1;
const int EVENT_BUTTON_REPEAT = 2;
const int EVENT_BUTTON_TAP = 3;
const int EVENT_BUTTON_HOLD = 4;

#endif
