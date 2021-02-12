#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "EEPROM_TC.h"

unittest(Main) {
  // Test singleton
  EEPROM_TC* singleton1 = nullptr;
  singleton1 = EEPROM_TC::instance();
  assertNotNull(singleton1);
  EEPROM_TC* singleton2 = nullptr;
  singleton2 = EEPROM_TC::instance();
  assertNotNull(singleton2);
  assertEqual(singleton1, singleton2);
}

unittest(PH) {
  EEPROM_TC* singleton = EEPROM_TC::instance();
  assertEqual(singleton->getPH(), 255);

  singleton->setPH(3);
  assertEqual(singleton->getPH(), 3);
}

unittest_main()
