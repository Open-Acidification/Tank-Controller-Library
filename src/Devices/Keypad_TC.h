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
  static Keypad keypad;
  static const byte ROWS;
  static const byte COLS;
  static const char STD_KEYS[ROWS][COLS];
  static const byte ROW_PINS[ROWS];
  static const byte COL_PINS[COLS];
  
  // instance methods
  Keypad_TC();
};
