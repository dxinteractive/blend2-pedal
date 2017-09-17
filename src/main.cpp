/*
 * audio
 * Main program file for Blend^2 guitar pedal loop blender and router.
 * Copyright (c) 2017 Damien Clarke
 * damienclarke.me | github.com/dxinteractive/Blend2
 *
 * |~)| _  _  _| 2
 * |_)|(/_| |(_|
 *
 */

#include <Arduino.h>
#include <Wire.h>

// SSD1306
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// inputs
#include <AnalogMultiButton.h>
#include <ResponsiveAnalogRead.h>

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

Adafruit_SSD1306 screen(PIN_SID, PIN_SCLK, PIN_DC, PIN_RST, PIN_CS);

ResponsiveAnalogRead analog0(PIN_ANALOG_0, true);
ResponsiveAnalogRead analog1(PIN_ANALOG_1, true);
ResponsiveAnalogRead analogExp(PIN_ANALOG_EXP, true);

const int BUTTONS_TOTAL = 4;
const int BUTTONS_VALUES[BUTTONS_TOTAL] = {0, 256, 512, 768};
AnalogMultiButton buttons(PIN_BUTTONS, BUTTONS_TOTAL, BUTTONS_VALUES);

const int BUTTON_UP = 0;
const int BUTTON_LEFT = 1;
const int BUTTON_DOWN = 2;
const int BUTTON_RIGHT = 3;

// const int ROUTES_Y_TOP = 14;
// const int ROUTES_Y_MIDDLE = 24;
// const int ROUTES_Y_BOTTOM = 34;
// const int ROUTES_Y_MIDLINE = 7;

// int blend_dry_send = 255;
// int blend_wet_send = 255;
// int blend_dry_return = 255;
// int blend_wet_return = 255;

// int relay_y_loop = 0; // 0 off, 1 dry pos, 2 wet pos
// int relay_z_loop = 0; // 0 off, 1 dry pos, 2 wet pos, 3 dmm
// int relay_stereo = 0; // 0 split, 1 stereo

// int shuffler_selector_1; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
// int shuffler_selector_2; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
// int shuffler_selector_3; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
// int shuffler_selector_4; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
// int shuffler_input_switch; // 0 off, 1 on
// int shuffler_selector_switch_1; // 0 normal, 1 Z loop is in use
// int shuffler_selector_switch_2; // 0 normal, 1 Z loop is in use
// int shuffler_output_switch; // 0 normal, 1 F loop is in front, 2 off

// int renderOpenSplit(int x, int top, int middle, int bottom) {
//   screen.fillRect(x, ROUTES_Y_MIDLINE + middle, 4, 1, WHITE);
//   screen.fillRect(4 + x, ROUTES_Y_MIDLINE + top, 1, bottom - top + 1, WHITE);
//   screen.fillRect(5 + x, ROUTES_Y_MIDLINE + top, 3, 1, WHITE);
//   screen.fillRect(5 + x, ROUTES_Y_MIDLINE + bottom, 3, 1, WHITE);
//   return x + 8;
// }

// int renderCloseSplit(int x, int top, int middle, int bottom) {
//   screen.fillRect(x, ROUTES_Y_MIDLINE + top, 2, 1, WHITE);
//   screen.fillRect(x, ROUTES_Y_MIDLINE + bottom, 2, 1, WHITE);
//   screen.fillRect(2 + x, ROUTES_Y_MIDLINE + top, 1, bottom - top + 1, WHITE);
//   screen.fillRect(3 + x, ROUTES_Y_MIDLINE + middle, 3, 1, WHITE);
//   return x + 6;
// }

// int renderLetter(int x, int y, char letter) {
//   screen.setTextColor(WHITE);
//   screen.setTextSize(2);
//   screen.setCursor(x + 2, y);
//   screen.println(letter);
//   screen.fillRect(14 + x, ROUTES_Y_MIDLINE + y, 2, 1, WHITE);
//   return x + 16;
// }

// int renderDash(int x, int y) {
//   screen.fillRect(x, ROUTES_Y_MIDLINE + y, 16, 1, WHITE);
//   return x + 16;
// }

void setup() {
  // Wire.begin(); // connect with shuffler
  Serial.begin(9600);

  // screen
  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setTextSize(2);
  screen.println("Hello! :)");
  screen.display();

  // relays
  pinMode(PIN_RELAY_0, OUTPUT);
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);
  digitalWrite(PIN_RELAY_0, LOW);
  digitalWrite(PIN_RELAY_1, LOW);
  digitalWrite(PIN_RELAY_2, LOW);
  digitalWrite(PIN_RELAY_3, LOW);
  digitalWrite(PIN_RELAY_4, LOW);

  // vactrols
  pinMode(PIN_VACTROL_0, OUTPUT);
  pinMode(PIN_VACTROL_1, OUTPUT);
  pinMode(PIN_VACTROL_2, OUTPUT);
  pinMode(PIN_VACTROL_3, OUTPUT);
  analogWriteFrequency(PIN_VACTROL_0, 36000);
  analogWriteFrequency(PIN_VACTROL_1, 36000);
  analogWriteFrequency(PIN_VACTROL_2, 36000);
  analogWriteFrequency(PIN_VACTROL_3, 36000);
  digitalWrite(PIN_VACTROL_0, LOW);
  digitalWrite(PIN_VACTROL_1, LOW);
  digitalWrite(PIN_VACTROL_2, LOW);
  digitalWrite(PIN_VACTROL_3, LOW);

  // leds
  pinMode(PIN_LED_UP, OUTPUT);
  pinMode(PIN_LED_DOWN, OUTPUT);
  pinMode(PIN_LED_LEFT, OUTPUT);
  pinMode(PIN_LED_RIGHT, OUTPUT);
  analogWriteFrequency(PIN_LED_UP, 36000);
  analogWriteFrequency(PIN_LED_DOWN, 36000);
  analogWriteFrequency(PIN_LED_LEFT, 36000);
  analogWriteFrequency(PIN_LED_RIGHT, 36000);
  digitalWrite(PIN_LED_UP, LOW);
  digitalWrite(PIN_LED_DOWN, LOW);
  digitalWrite(PIN_LED_LEFT, LOW);
  digitalWrite(PIN_LED_RIGHT, LOW);

  // analog
  analog0.setSnapMultiplier(0.001);
  analog1.setSnapMultiplier(0.001);
  analogExp.setSnapMultiplier(0.001);
}

void loop() {

  //
  // READ FROM SHUFFLER
  //
  
  // Wire.requestFrom(8, 8);
  // if(Wire.available()) {
  // 	shuffler_selector_1 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_selector_2 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_selector_3 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_selector_4 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_input_switch = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_selector_switch_1 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_selector_switch_2 = Wire.read();
  // }
  // if(Wire.available()) {
  // 	shuffler_output_switch = Wire.read();
  // }

  // screen.clearDisplay();
  // int x = 0;
  // x = renderOpenSplit(x, ROUTES_Y_TOP, ROUTES_Y_MIDDLE, ROUTES_Y_BOTTOM);

  // renderLetter(x, ROUTES_Y_TOP, 'L');
  // x = renderLetter(x, ROUTES_Y_BOTTOM, 'E');

  // x = renderCloseSplit(x, ROUTES_Y_TOP, ROUTES_Y_MIDDLE, ROUTES_Y_BOTTOM);

  // x = renderLetter(x, ROUTES_Y_MIDDLE, 'D');

  // x = renderLetter(x, ROUTES_Y_MIDDLE, 'B');

  // x = renderLetter(x, ROUTES_Y_MIDDLE, 'A');

  // screen.display();

  // analog
  analog0.update();
  analog1.update();
  analogExp.update();

  int a = 1024 - analog0.getValue();

  Serial.println();
  Serial.println(analog1.getValue());
  Serial.println(analogExp.getValue());

  // button
  buttons.update();
  if(buttons.isPressed(BUTTON_UP)) {
    digitalWrite(PIN_RELAY_0, HIGH);
    digitalWrite(PIN_RELAY_1, HIGH);
    digitalWrite(PIN_RELAY_2, HIGH);
    digitalWrite(PIN_RELAY_3, HIGH);
    digitalWrite(PIN_RELAY_4, HIGH);
  } else {
    digitalWrite(PIN_RELAY_0, LOW);
    digitalWrite(PIN_RELAY_1, LOW);
    digitalWrite(PIN_RELAY_2, LOW);
    digitalWrite(PIN_RELAY_3, LOW);
    digitalWrite(PIN_RELAY_4, LOW);
  }

  analogWrite(PIN_VACTROL_0, a * 0.25);
  analogWrite(PIN_VACTROL_1, a * 0.25);
  analogWrite(PIN_VACTROL_2, a * 0.25);
  analogWrite(PIN_VACTROL_3, a * 0.25);
  analogWrite(PIN_LED_UP, a * 0.25);
  analogWrite(PIN_LED_DOWN, a * 0.25);
  analogWrite(PIN_LED_LEFT, a * 0.25);
  analogWrite(PIN_LED_RIGHT, a * 0.25);

  // if(buttons.isPressed(BUTTON_DOWN)) {
  //   analogWrite(PIN_LED_DOWN, 128);
  // } else {
  //   analogWrite(PIN_LED_DOWN, 0);
  // }

  // if(buttons.isPressed(BUTTON_LEFT)) {
  //   analogWrite(PIN_LED_LEFT, 128);
  // } else {
  //   analogWrite(PIN_LED_LEFT, 0);
  // }

  // if(buttons.isPressed(BUTTON_RIGHT)) {
  //   analogWrite(PIN_LED_RIGHT, 128);
  // } else {
  //   analogWrite(PIN_LED_RIGHT, 0);
  // }

  // screen.clearDisplay();
  // screen.setTextColor(WHITE);
  // screen.setTextSize(2);
  // screen.println("...");
  // screen.display();

  // digitalWrite(PIN_RELAY_0, LOW);
  // digitalWrite(PIN_RELAY_1, LOW);
  // digitalWrite(PIN_RELAY_2, LOW);
  // digitalWrite(PIN_RELAY_3, LOW);
  // digitalWrite(PIN_RELAY_4, LOW);
  // analogWrite(PIN_VACTROL_0, 10);
  // analogWrite(PIN_VACTROL_1, 10);
  // analogWrite(PIN_VACTROL_2, 10);
  // analogWrite(PIN_VACTROL_3, 10);
  // analogWrite(PIN_LED_RIGHT, 0);
  // delay(1000);

  // digitalWrite(PIN_RELAY_0, HIGH);
  // digitalWrite(PIN_RELAY_1, HIGH);
  // digitalWrite(PIN_RELAY_2, HIGH);
  // digitalWrite(PIN_RELAY_3, HIGH);
  // digitalWrite(PIN_RELAY_4, HIGH);
  // analogWrite(PIN_VACTROL_0, 25);
  // analogWrite(PIN_VACTROL_1, 25);
  // analogWrite(PIN_VACTROL_2, 25);
  // analogWrite(PIN_VACTROL_3, 25);
  // analogWrite(PIN_LED_RIGHT, 128);
  delay(1);
}