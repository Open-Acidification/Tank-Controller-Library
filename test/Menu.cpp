#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "TankControllerLib.h"

unittest(test) {
  TankControllerLib* tc = TankControllerLib::instance();
  LiquidCrystal_TC* lc = LiquidCrystal_TC::instance();
  Keypad_TC* keypad = Keypad_TC::instance();
  Keypad* puppet = keypad->_getPuppet();
  std::vector<std::string> lines;
  tc->loop();
  lines = lc->getLines();
  assertEqual("Main Menu       ", lines.at(0));
  puppet->push_back('A');
  tc->loop();
  lines = lc->getLines();
  assertEqual("Set pH Set Point", lines.at(0));
}

unittest_main()
