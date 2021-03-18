#include <Arduino.h>
#include <ArduinoUnitTests.h>
#include <EEPROM.h>

#include "EEPROM_TC.h"

/*
 * If the first four bytes aren't a valid version,
 * then we use the legacy layout.
 *
 * This is in a separate test because the other
 * tests are based on a boot/reset contents.
 */
unittest(getVersion2) {
  for (int i = 0; i < 4; ++i) {
    EEPROM.update(i, 1);
  }
  EEPROM_TC* eeprom = EEPROM_TC::instance();
  assertEqual(2, eeprom->getVersion());
}

unittest_main()
