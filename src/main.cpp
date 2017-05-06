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

const int PIN_SID = 4;
const int PIN_SCLK = 3;
const int PIN_DC = 2;
const int PIN_RST = 1;
const int PIN_CS = 0;

Adafruit_SSD1306 screen(PIN_SID, PIN_SCLK, PIN_DC, PIN_RST, PIN_CS);

int shuffler_selector_1; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
int shuffler_selector_2; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
int shuffler_selector_3; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
int shuffler_selector_4; // 0 A, 1 B, 2 C, 3 D, 4 E, 5 bypass
int shuffler_input_switch; // 0 off, 1 on
int shuffler_selector_switch_1; // 0 normal, 1 Z loop is in use
int shuffler_selector_switch_2; // 0 normal, 1 Z loop is in use
int shuffler_output_switch; // 0 normal, 1 F loop is in front, 2 off

void setup() {
  Wire.begin(); // connect with shuffler
  Serial.begin(9600);

  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.fillRect(4,4,4,4,WHITE);
  screen.display();
}

void loop() {

  //
  // READ FROM SHUFFLER
  //
  
  Wire.requestFrom(8, 8);
  if(Wire.available()) {
  	shuffler_selector_1 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_selector_2 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_selector_3 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_selector_4 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_input_switch = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_selector_switch_1 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_selector_switch_2 = Wire.read();
  }
  if(Wire.available()) {
  	shuffler_output_switch = Wire.read();
  }

  delay(50);
}