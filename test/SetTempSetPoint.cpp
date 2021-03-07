#include "SetTempSetPoint.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <iostream>

#include "EEPROM_TC.h"

unittest(Test) {
  SetTempSetPoint test;
  test.setValue(50.05);
  assertEqual(50.05, EEPROM_TC::instance()->getTemp());
}

unittest_main()
