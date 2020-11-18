#pragma once
#include <Arduino.h>

#define VERSION "0.3.0"

class UIState;
class TankControllerLib {
public:
  static TankControllerLib* instance();
  void setup();
  void loop();
  const char* version() {
    return VERSION;
  }

protected:
  TankControllerLib();
  ~TankControllerLib();

private:
  friend class UIState;
  void changeState(UIState* newState);
  UIState* _state;
  static TankControllerLib* _instance;
};
