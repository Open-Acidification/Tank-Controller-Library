#include <Arduino.h>
#include <ArduinoUnitTests.h>
#include "EEPROM_TC.h"

unittest(pHSetPoint) {
    EEPROM_TC eeprom;
    eeprom.writepHSetPoint(7.1);
    double value = eeprom.readpHsetPoint();
    assertEqual(7.1, value);
}

unittest(readTempSetPoint) {
    EEPROM_TC eeprom;
    eeprom.readTempSetPoint();
}

unittest(doubleWrite) {
    EEPROM_TC eeprom;
    eeprom.doubleWrite(0, 3);
    double value = eeprom.read(0);
    assertEqual(3, value);
}

unittest(doubleRead) {
    EEPROM_TC eeprom;
    eeprom.doubleRead(2.3);
    double value = eeprom.readdoubleRead();
    assertEqual(2.3, value);
}

unittest_main()

