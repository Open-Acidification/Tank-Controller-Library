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
  virtual void setNextState(UIState* newState) {
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
    assert(nextState == nullptr);
    nextState = newState;
  }

protected:
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

#ifdef MOCK_PINS_COUNT
class TankControllerLibTest : public TankControllerLib {
public:
  void setNextState(UIState* newState) {
    assert(nextState == nullptr);
    nextState = newState;
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
    updateState();
    std::cout << __FILE__ << ":" << __LINE__ << std::endl;
  }
  bool isOnMainMenu();
};
#endif
