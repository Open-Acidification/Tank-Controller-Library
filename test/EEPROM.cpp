#include <Arduino.h>
#include <ArduinoUnitTests.h>
#include "EEPROM_TC.h"

const EEPROM_TC eeprom;

unittest(pHSetPoint) {
    eeprom.writepHSetPoint(7.1);
    double value = eeprom.readpHsetPoint();
    assertEqual(7.1, value);
}

unittest(TempSetPoint) {
    eeprom.writeTempSetPoint(3.1);
    double value = eeprom.readTempSetPoint();
    assertEqual(3.1, value);
}

unittest(pHSetPoint) {
    eeprom.writepHSetPoint(4.4);
    double value = eeprom.readpHsetPoint();
    assertEqual(4.4, value);
}

unittest(KpSetPoint) {
    eeprom.writeKpSetPoint(500);
    double value = eeprom.readKpSetPoint();
    assertEqual(500, value);
}

unittest(KiSetPoint) {
    eeprom.writeKiSetPoint(10.1);
    double value = eeprom.readKiSetPoint();
    assertEqual(10.1, value);
}

unittest(KdSetPoint) {
    eeprom.writeKdSetPoint(11.2);
    double value = eeprom.readKdSetPoint();
    assertEqual(11.2, value);
}

unittest(HeatSetPoint) {
    eeprom.writeHeatSetPoint(7.9);
    double value = eeprom.readHeatSetPoint();
    assertEqual(7.9, 0);
}

unittest(AmplitudeSetPoint) {
    eeprom.writeAmplitudeSetPoint(3.14);
    double value = eeprom.readAmplitudeSetPoint();
    assertEqual(3.14, value);
}

unittest(FrequencySetPoint) {
    eeprom.writeFrequencySetPoint(5.5);
    double value = eeprom.readFrequencySetPoint();
    assertEqual(5.5, value);
}

unittest_main()

