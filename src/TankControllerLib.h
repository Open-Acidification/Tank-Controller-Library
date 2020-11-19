#pragma once
#include <Arduino.h>
#include "Devices/LiquidCrystal_TC.h"

const char TANK_CONTROLLER_VERSION[] = "0.3.0";

class UIState;
class TankControllerLib {
public:
  static TankControllerLib* instance();
  void setup();
  void loop();
  const char* version() {
    return TANK_CONTROLLER_VERSION;
  }

protected:
  TankControllerLib();
  ~TankControllerLib();

private:
  // class (static) variables
  static TankControllerLib* _instance;

  // instance variables
  UIState* _state;
  LiquidCrystal_TC *lcd;

  // private member functions
  void blink();
  void changeState(UIState* newState);

  // other classes with access to our privates
  friend class UIState;
};
