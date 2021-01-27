#pragma once

#include <Arduino.h>
#ifdef MOCK_PINS_COUNT
#include <Keypad_CI.h>
#else
#include <Keypad.h>
#endif

class Keypad_TC {
public:
  // class methods
  static Keypad_TC* instance();

  // Public
  char waitForKey();
  char getKey();

private:
  // class variables
  static Keypad_TC* _instance;
  Keypad puppetPad;
  
  // instance methods
  Keypad_TC();
};
