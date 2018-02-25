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

#include "View.h"
#include <Stackui.h>
#include <Arduino.h>
#include "Props.h"
#include "../config.h"

static int BLEND_BOX_W = 31;
static int BLEND_BOX_H = 22;
static int BLEND_BOX_ROWH = 13;
static int BLEND_BOX_MARGINX = 15;
static int BLEND_BOX_COLX = 64 - (BLEND_BOX_W / 2);
static int BLEND_BOX_PADDINGX = 5;
static int BLEND_BOX_GRAPHH = 10;
static int BLEND_GRAPHW = 20;

static char const* SHUFFLER_SELECTOR_LETTERS = "ABCD--";
static char NC = ' ';
static char GAP = '-';

void View::setup()
{
  ledController.setup();

  screen.begin(SSD1306_SWITCHCAPVCC);
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  //screen.setTextSize(2);
  //screen.println("hello :D");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  // screen.println("RRRRRRRRRR");
  screen.display();
}



void View::render(StackuiProps &props)
{
  switch(props.getId())
  {
    case PropsBlendSelector::id:
      return render(static_cast<PropsBlendSelector&>(props));

    case PropsRouteSelector::id:
      return render(static_cast<PropsRouteSelector&>(props));

    case PropsBlendLeds::id:
      return render(static_cast<PropsBlendLeds&>(props));
  }
}

void View::render(PropsBlendSelector &props)
{
  screen.clearDisplay();
  screen.setTextColor(WHITE);
  screen.setTextSize(1);

  int dotX = 64 - (((BLEND_BOX_ROWH * 2) + BLEND_BOX_H) * 3 / 4);
  int dotY = (BLEND_BOX_ROWH * 2) + BLEND_BOX_H - 1;
  while(dotY > 0)
  {
    screen.drawPixel(dotX, dotY, WHITE);
    dotX += 3;
    dotY -= 2;
  }

  PropsBlendGraph drySend;
  //drySend.selected = true;
  drySend.start = props.ampKeyframeValues[0];
  drySend.end = props.ampKeyframeValues[1];
  renderGraphic(129 - BLEND_BOX_MARGINX - BLEND_BOX_W, BLEND_BOX_ROWH, drySend);

  PropsBlendGraph wetSend;
  wetSend.start = props.ampKeyframeValues[2];
  wetSend.end = props.ampKeyframeValues[3];
  renderGraphic(BLEND_BOX_COLX, 0, wetSend);

  PropsBlendGraph dryReturn;
  dryReturn.start = props.ampKeyframeValues[4];
  dryReturn.end = props.ampKeyframeValues[5];
  renderGraphic(BLEND_BOX_COLX, (BLEND_BOX_ROWH * 2), dryReturn);

  PropsBlendGraph wetReturn;
  wetReturn.start = props.ampKeyframeValues[6];
  wetReturn.end = props.ampKeyframeValues[7];
  renderGraphic(BLEND_BOX_MARGINX, BLEND_BOX_ROWH, wetReturn);

  screen.setCursor(0, 56);
  screen.print("<");
  screen.setCursor(64 - (strlen(props.presetName) * 3),56);
  screen.println(props.presetName);
  screen.setCursor(120, 56);
  screen.print(">");
  screen.display();
}

void View::renderGraphic(int x, int y, PropsBlendGraph &props)
{
  float start = (float)props.start;
  float end = (float)props.end;

  screen.fillRect(x - 1, y - 1, BLEND_BOX_W + 2, BLEND_BOX_H + 2, BLACK);
  //screen.drawRect(x, y, BLEND_BOX_W, BLEND_BOX_H, WHITE);

  if(props.selected)
  {
    screen.drawFastHLine(x, y, 3, WHITE);
    screen.drawFastHLine(x + BLEND_BOX_W - 3, y, 3, WHITE);
    screen.drawFastHLine(x, y + BLEND_BOX_H - 1, 3, WHITE);
    screen.drawFastHLine(x + BLEND_BOX_W - 3, y + BLEND_BOX_H - 1, 3, WHITE);
    screen.drawFastVLine(x, y, 2, WHITE);
    screen.drawFastVLine(x, y + BLEND_BOX_H - 2, 2, WHITE);
    screen.drawFastVLine(x + BLEND_BOX_W - 1, y, 2, WHITE);
    screen.drawFastVLine(x + BLEND_BOX_W - 1, y + BLEND_BOX_H - 2, 2, WHITE);
  }

  int midY = y + (BLEND_BOX_H / 2);
  int graphx1 = x + BLEND_BOX_PADDINGX;
  for(int i = 0; i <= BLEND_GRAPHW; i++)
  {
    float c = (float)i / (float)BLEND_GRAPHW;
    float amp = (c * (end - start)) + start;
    if(amp > 1.0) amp = 1.0;
    if(amp < 0.0) amp = 0.0;
    int gx = i + graphx1;
    float ampScaled = (float)BLEND_BOX_GRAPHH * amp;
    int gty = midY - ampScaled;
    int gby = midY + ampScaled;

    screen.drawFastVLine(gx, gty, 1, WHITE);
    screen.drawFastVLine(gx, gby, 2, WHITE);

    if(i == 0 || i == BLEND_GRAPHW)
      screen.drawFastVLine(gx, gty, gby - gty, WHITE);
  }
}

void View::render(PropsRouteSelector &props)
{
  screen.clearDisplay();
  screen.setTextColor(WHITE);

  renderGraphic(10, 10, props);

  screen.setTextSize(1);
  screen.setCursor(0, 56);
  screen.print(props.zPositionLabel);
  screen.setCursor(52, 56);
  screen.print(props.polarityOptionLabel);
  screen.setCursor(127 - (strlen(props.dryPositionLabel) * 6), 56);
  screen.print(props.dryPositionLabel);

  screen.display();
}

void View::renderGraphic(int x, int y, PropsRouteSelector &props)
{
  char upper[] = {NC,NC,NC,NC,NC,NC,NC,NC,NC,NC};
  char lower[] = {NC,NC,NC,NC,NC,NC,NC,NC,NC,NC};
  int upperCursor = 2;

  // get prop data
  int outputSwitch = props.shufflerData->outputSwitch;
  int const* selectors = props.shufflerData->selectors;
  int selector0Z = props.shufflerData->selector0Z;
  int selector1Z = props.shufflerData->selector1Z;

  // insert F if output switch places it at front
  if(outputSwitch > 0)
    upper[upperCursor++] = outputSwitch == 2 ? 'X' : 'F';

  // find split position
  int splitPos = 0;
  for(int i = 0; i < 4; i++)
  {
    if(selectors[i] == 3)
    {
      splitPos = upperCursor + i;
      break;
    }
  }

  // add lower cursor and split icon at split position
  int lowerCursor = splitPos + 1;
  lower[splitPos] = '/';

  // add selectors to upper
  upper[upperCursor++] = selector0Z ? GAP : SHUFFLER_SELECTOR_LETTERS[selectors[0]];
  upper[upperCursor++] = selector1Z ? GAP : SHUFFLER_SELECTOR_LETTERS[selectors[1]];
  upper[upperCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[2]];
  upper[upperCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[3]];

  // add E to lower if split
  if(props.dryPosition == 0)
    lower[lowerCursor++] = 'E';

  if(props.zPosition == 1) // Dry z loop
  {
    if(selector0Z)
      lower[lowerCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[0]];

    if(selector1Z)
      lower[lowerCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[1]];
  }

  if(props.zPosition == 3) // DMM z loop
  {
    int dmmCursor = splitPos;
    if(selector1Z)
      lower[--dmmCursor] = SHUFFLER_SELECTOR_LETTERS[selectors[1]];

    if(selector0Z)
      lower[--dmmCursor] = SHUFFLER_SELECTOR_LETTERS[selectors[0]];
  }

  // find join position
  lowerCursor = upperCursor > lowerCursor ? upperCursor : lowerCursor;

  // fill gaps between upper and lower
  for(int i = splitPos; i < lowerCursor; i++)
  {
    if(upper[i] == NC && lower[i] != NC)
      upper[i] = GAP;

    if(upper[i] != NC && lower[i] == NC)
      lower[i] = GAP;
  }

  // add joiners
  upper[lowerCursor] = '/';
  lower[lowerCursor++] = '-';

  if(props.zPosition == 2) // After z loop
  {
    if(selector0Z)
      lower[lowerCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[0]];

    if(selector1Z)
      lower[lowerCursor++] = SHUFFLER_SELECTOR_LETTERS[selectors[1]];
  }

  // add E to lower if not split
  if(props.dryPosition == 1)
    lower[lowerCursor++] = 'E';

  // add output switch
  if(outputSwitch == 0)
  {
    lower[lowerCursor++] = 'F';
  }

  // render
  int xx = 110;
  for(int i = 0; i < 10; i++)
  {
    if(upper[i] != NC || lower[i] != NC)
    {
      screen.setTextSize(2);
      screen.setCursor(xx, 10);
      screen.println(upper[i]);
      screen.setCursor(xx, 30);
      screen.println(lower[i]);
      xx -= 14;
    }
  }
}

void View::renderGraphic(int x, int y, PropsRouteLetter &props)
{
  screen.setCursor(x, y);
  screen.setTextSize(2);
  screen.println(props.letter);
}

void View::render(PropsBlendLeds &props)
{
  ledController.setBrightness(LED_UP, props.wetSend);
  ledController.setBrightness(LED_DOWN, props.dryReturn);
  ledController.setBrightness(LED_LEFT, props.wetReturn);
  ledController.setBrightness(LED_RIGHT, props.drySend);
}
