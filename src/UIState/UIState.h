/*
 * Abstract superclass for the TankController UI states
 * Concrete subclass for the initial (start) state
 */

#pragma once

#include "../TankControllerLib.h"

class UIState {
public:
  UIState() {
  }
  virtual ~UIState() {
  }
  virtual void handleKey(char key) = 0;

protected:
  void changeState(UIState* state) {
    TankControllerLib::singleton()->changeState(state);
  }
};

class UIStart : UIState {
public:
  UIStart() {
  }
  ~UIStart() {
  }
  virtual void handleKey(char key);
};
