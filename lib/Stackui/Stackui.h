/*
 * Stackui.h
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

#ifndef STACKUI_H
#define STACKUI_H

#include <Arduino.h>
#include <StackArray.h>
#include "StackuiModel.h"
#include "StackuiInput.h"
#include "StackuiView.h"
#include "StackuiProps.h"
#include "StackuiState.h"
#include "StackuiEvent.h"

class Stackui
{
  public:
    Stackui(
      StackuiModel& model,
      StackuiInput& input,
      StackuiView& view,
      StackuiState* initialState
    );

    Stackui(
      StackuiModel& model,
      StackuiInput& input,
      StackuiView& view,
      StackuiState** initialStates,
      int initialStatesTotal
    );

    ~Stackui();

    void pushState(StackuiState* newState, bool render = true);
    void replaceState(StackuiState* newState, bool render = true);
    void popState(bool render = true);

    void setup();
    void update(unsigned long ms);
    void renderFrame(unsigned long ms);
    void renderProps(StackuiProps &props);
    StackuiModel* getStackuiModel();

    void onEvent(StackuiEvent &e);

  private:
    StackuiModel* model;
    StackuiInput* input;
    StackuiView* view;
    StackArray <StackuiState*> stateStack;
};

#endif
