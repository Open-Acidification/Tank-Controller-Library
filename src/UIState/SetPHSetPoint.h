/**
 * SetPHSetPoint.h
 *
 * Handle top-level menu option
 */
#pragma once
#include "UIState.h"

class SetPHSetPoint : public UIState {
public:
  virtual void handleKey(char key) {
  }
  const char *prompt() { return "Set pH Set Point"; };
};
