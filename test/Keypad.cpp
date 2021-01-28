#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "TankControllerLib.h"

unittest(constructor) {
  // Test singleton
  Keypad_TC* singleton1 = nullptr;
  singleton1 = Keypad_TC::instance();
  assertNotNull(singleton1);
  Keypad_TC* singleton2 = nullptr;
  singleton2 = Keypad_TC::instance();
  assertNotNull(singleton2);
  assertEqual(singleton1, singleton2);
}

unittest(getKey) {
  Keypad_TC* testKeypad = Keypad_TC::instance();
  testKeypad->push_back('Q');
  assertEqual('Q', testKeypad->getKey());
}

unittest(waitForKey) {
  Keypad_TC* testKeypad = Keypad_TC::instance();
  testKeypad->push_back('Q');
  assertEqual('Q', testKeypad->waitForKey());
}

unittest_main()
