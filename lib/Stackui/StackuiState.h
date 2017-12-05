/*
 * StackuiState.h
 * A stack-based UI state manager for Arduino
 * Base class for a user interface state
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

#ifndef STACKUI_STATE_H
#define STACKUI_STATE_H

#include "StackuiModel.h"
#include "StackuiProps.h"
#include "StackuiEvent.h"

// forward declarations
class Stackui;

class StackuiState
{
  public:
    StackuiState() {}
    virtual ~StackuiState() {}

    void init(Stackui* const ui);
    void init(Stackui* const ui, StackuiState* const lowerState);
    virtual void init() {}
    // ^ this init call can be overriden by derived classes and is called after init(ui) is called

    virtual void update(unsigned long ms) {}
    void updateTimeout(unsigned long ms);

    virtual void onEvent(StackuiEvent &e) {}
    virtual void onFrame(unsigned long ms) {}
    virtual void render() {}

  protected:
    void pushState(StackuiState* newState);
    void replaceState(StackuiState* newState);
    void popState();

    void renderProps(StackuiProps &props);
    void passEvent(StackuiEvent &e);
    StackuiModel* getStackuiModel();

  private:
    unsigned long timeout = 0;
    StackuiState* lowerState;
    Stackui* ui;
};

#endif
