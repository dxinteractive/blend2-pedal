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
#include "StackuiEvent.h"
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
  this->pushState(initialState, false);
}

Stackui::Stackui(
  StackuiModel& model,
  StackuiInput& input,
  StackuiView& view,
  StackuiState** initialStates,
  int initialStatesTotal
):
  model(&model),
  input(&input),
  view(&view)
{
  model.init(this);
  input.init(this);
  view.init(this);
  for(int i = 0; i < initialStatesTotal; i++)
    this->pushState(initialStates[i], false);
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
  model->setup();
  input->setup();
  view->setup();

  StackuiState* topState = stateStack.peek();
  if(topState)
    topState->render();
}

void Stackui::update(unsigned long ms)
{
  StackuiState* topState = stateStack.peek();
  if(topState)
  {
    topState->updateTimeout(ms);
    topState->update(ms);
  }
}

void Stackui::renderFrame(unsigned long ms = 0)
{
  if(stateStack.isEmpty())
    return;

  StackuiState* topState = stateStack.peek();
  topState->onFrame(ms);
}

void Stackui::pushState(StackuiState* newState, bool render)
{
  StackuiState* topState = NULL;
  if(!stateStack.isEmpty())
  {
    topState = stateStack.peek();
    if(newState == topState)
      return;
  }

  stateStack.push(newState);
  newState->init(this, topState);
  if(render)
    newState->render();
}

void Stackui::replaceState(StackuiState* newState, bool render)
{
  if(stateStack.isEmpty())
    return;

  StackuiState* topState = stateStack.peek();
  if(newState == topState || stateStack.count() < 2)
    return;

  stateStack.pop();
  delete topState;

  topState = stateStack.peek();
  stateStack.push(newState);
  newState->init(this, topState);
  if(render)
    newState->render();
}

void Stackui::popState(bool render)
{
  if(stateStack.count() < 2)
    return;

  StackuiState* topState = stateStack.peek();
  stateStack.pop();
  delete topState;
  if(render)
    stateStack.peek()->render();
}

void Stackui::renderProps(StackuiProps &props)
{
  view->render(props);
}

void Stackui::onEvent(StackuiEvent &e)
{
  StackuiState* topState = stateStack.peek();
  if(!topState)
    return;

  topState->onEvent(e);
}

StackuiModel* Stackui::getStackuiModel()
{
  return model;
}
