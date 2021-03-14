#pragma once
#include <Arduino.h>

#include <cassert>

#include "Devices/LiquidCrystal_TC.h"
#include "Devices/Serial_TC.h"

const char TANK_CONTROLLER_VERSION[] = "0.3.0";

class UIState;
class TankControllerLib {
public:
  // class methods
  static TankControllerLib* instance();

  // instance methods
  void setup();
  void loop();
  const char* version();
  void setNextState(UIState* newState) {
    assert(nextState == nullptr);
    nextState = newState;
  }

  // Backdoor for testing current state
  char* getPrompt() {
    return state->prompt();
  }

private:
  // class variables
  static TankControllerLib* _instance;

  // instance variables
  UIState* state = nullptr;
  UIState* nextState = nullptr;
  LiquidCrystal_TC* lcd;
  Serial_TC* log;

  // instance methods
  TankControllerLib();
  ~TankControllerLib();
  void blink();
  void updateState();
  void handleUI();
};
