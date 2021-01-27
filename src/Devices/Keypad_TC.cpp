#include "Devices/Keypad_TC.h"

//  class variables
Keypad_TC* Keypad_TC::_instance = nullptr;
const Keypad_TC::byte ROWS = 4;
const Keypad_TC::byte COLS = 4;
const Keypad_TC::char STD_KEYS[ROWS][COLS] = {
    {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
const Keypad_TC::byte ROW_PINS[ROWS] = {34, 36, 38, 40};
const Keypad_TC::byte COL_PINS[COLS] = {42, 44, 46, 48};
Keypad Keypad_TC::keypad = Keypad(makeKeymap(STD_KEYS), ROW_PINS, COL_PINS, ROWS, COLS);

//  class methods
/**
 * accessor for singleton
 */
Keypad_TC* Keypad_TC::instance() {
  if (!_instance) {
    _instance = new Keypad_TC();
  }
  return _instance;
}

char Keypad_TC::waitForKey() {
    return 'Q';
}
char Keypad_TC::getKey() {
    return 'Q';
}
