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
static const int PIN_RELAY_0 = 0;
static const int PIN_RELAY_1 = 1;
static const int PIN_RELAY_2 = 2;
static const int PIN_VACTROL_0 = 3;
static const int PIN_VACTROL_1 = 4;
static const int PIN_VACTROL_2 = 5;
static const int PIN_VACTROL_3 = 6;
static const int PIN_SID = 7;
static const int PIN_SCLK = 8;
static const int PIN_DC = 9;
static const int PIN_RST = 10;
static const int PIN_CS = 11;
static const int PIN_RELAY_3 = 12;
static const int PIN_RELAY_4 = 13;
static const int PIN_ANALOG_EXP = A14;
static const int PIN_ANALOG_1 = A1;
static const int PIN_ANALOG_0 = A2;
static const int PIN_BUTTONS = A3;
static const int PIN_I2C_SDA = 18;
static const int PIN_I2C_SCL = 19;
static const int PIN_LED_DOWN = 20;
static const int PIN_LED_RIGHT = 21;
static const int PIN_LED_LEFT = 22;
static const int PIN_LED_UP = 23;

static const int AMP_DRY_SEND = 0;
static const int AMP_WET_SEND = 1;
static const int AMP_DRY_RETURN = 2;
static const int AMP_WET_RETURN = 3;
static const int AMPS_TOTAL = 4;

static const int KEYFRAMES_TOTAL = 2;

static const int BUTTONS_TOTAL = 4;
static const int BUTTONS_VALUES[BUTTONS_TOTAL] = {0, 256, 512, 768};
static const int BUTTONS_ASSIGN[BUTTONS_TOTAL] = {0, 2, 1, 3};

static const int EVENT_BUTTON = 0;
static const int EVENT_ANALOG = 1;
static const int EVENT_EXP = 2;
static const int EVENT_SHUFFLER = 3;

static const int EVENT_BUTTON_UP = 0;
static const int EVENT_BUTTON_DOWN = 1;
static const int EVENT_BUTTON_LEFT = 2;
static const int EVENT_BUTTON_RIGHT = 3;

static const int EVENT_BUTTON_VALUE_PRESS = 0;
static const int EVENT_BUTTON_VALUE_RELEASE = 1;
static const int EVENT_BUTTON_VALUE_REPEAT = 2;
static const int EVENT_BUTTON_VALUE_TAP = 3;
static const int EVENT_BUTTON_VALUE_HOLD = 4;

static const int EVENT_ANALOG_0 = 0;
static const int EVENT_ANALOG_1 = 1;

static const int EVENT_EXP_0 = 0;

static const int EVENT_SHUFFLER_CHANGED = 0;

static const int LED_UP = 0;
static const int LED_DOWN = 1;
static const int LED_LEFT = 2;
static const int LED_RIGHT = 3;

#endif
