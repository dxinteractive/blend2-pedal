/*
 * Stackui.cpp
 * A stack-based UI state manager for Arduino
 *
 * Copyright (c) 2017 Damien Clarke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Stackui.h"
#include <Arduino.h>

Stackui::Stackui(
  StackuiModel& model,
  StackuiInput& input,
  StackuiView& view,
  StackuiState* initialState
):
  model(&model),
  input(&input),
  view(&view)
{
  model.init(this);
  input.init(this);
  view.init(this);
  this->initialState(initialState);
}

Stackui::~Stackui()
{
  StackuiState* topState;
  while(!stateStack.isEmpty())
  {
    topState = stateStack.peek();
    stateStack.pop();
    delete topState;
  }
}

void Stackui::setup()
{
  StackuiState* topState = stateStack.peek();
  if(topState)
    topState->render();
}

void Stackui::update(unsigned long ms)
{
  StackuiState* topState = stateStack.peek();
  if(topState)
    topState->updateTimeout(ms);
    topState->update(ms);
}

void Stackui::renderFrame(unsigned long ms = 0)
{
  if(stateStack.isEmpty())
    return;

  StackuiState* topState = stateStack.peek();
  topState->onFrame(ms);
}

void Stackui::initialState(StackuiState* initialState)
{
  stateStack.push(initialState);
  initialState->init(this);
}

void Stackui::pushState(StackuiState* newState)
{
  StackuiState* topState = stateStack.peek();
  if(newState == topState)
    return;

  stateStack.push(newState);
  newState->init(this, topState);
  newState->render();
}

void Stackui::replaceState(StackuiState* newState)
{
  StackuiState* topState = stateStack.peek();
  if(newState == topState || stateStack.count() < 2)
    return;

  stateStack.pop();
  delete topState;

  topState = stateStack.peek();
  stateStack.push(newState);
  newState->init(this, topState);
  newState->render();
}

void Stackui::popState()
{
  if(stateStack.count() < 2)
    return;

  StackuiState* topState = stateStack.peek();
  stateStack.pop();
  delete topState;
  stateStack.peek()->render();
}

void Stackui::renderProps(StackuiProps &props)
{
  view->render(props);
}

void Stackui::onEvent(int type, int id, int value)
{
  StackuiState* topState = stateStack.peek();
  if(!topState)
    return;

  topState->onEvent(type, id, value);
}

void Stackui::onEvent(int type, int id, float value)
{
  StackuiState* topState = stateStack.peek();
  if(!topState)
    return;

  topState->onEvent(type, id, value);
}
