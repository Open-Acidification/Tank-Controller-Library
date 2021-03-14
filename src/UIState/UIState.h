/**
 * Abstract superclass for the TankController UI states
 * Concrete subclass for the initial (start) state
 */

#pragma once

#include "../TankControllerLib.h"

class UIState {
public:
  UIState(TankControllerLib* tc) {
    this->tc = tc;
  }
  virtual ~UIState() {
  }
  virtual void handleKey(char key) = 0;
  virtual const char* prompt() = 0;

protected:
  void setNextState(UIState* state) {
    tc->setNextState(state);
  }
  void returnToMainMenu() {
    setNextState(new MainMenu(tc));
  }
  TankControllerLib* tc = nullptr;
};
