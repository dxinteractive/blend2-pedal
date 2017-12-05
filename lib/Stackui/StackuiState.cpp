/*
 * StackuiState.cpp
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


#include "StackuiState.h"
#include "StackuiProps.h"
#include "Stackui.h"

void StackuiState::init(Stackui* const ui)
{
  this->ui = ui;
  init();
}

void StackuiState::init(Stackui* const ui, StackuiState* const lowerState)
{
  init(ui);
  this->lowerState = lowerState;
}

void StackuiState::updateTimeout(unsigned long ms)
{
  if(timeout > 0 && timeout < ms)
    popState();
}

void StackuiState::pushState(StackuiState* newState)
{
  ui->pushState(newState);
}

void StackuiState::replaceState(StackuiState* newState)
{
  ui->replaceState(newState);
}

void StackuiState::popState()
{
  ui->popState();
}

void StackuiState::renderProps(StackuiProps &props)
{
  ui->renderProps(props);
}

void StackuiState::passEvent(StackuiEvent &e)
{
  if(lowerState)
    lowerState->onEvent(e);
}

StackuiModel* StackuiState::getStackuiModel()
{
  return ui->getStackuiModel();
}
