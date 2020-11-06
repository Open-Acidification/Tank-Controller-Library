#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "EEPROM_TC.h"

EEPROM_TC eepromTC;

unittest(pHSetPoint) {
  eepromTC.writepHSetPoint(7.1);
  double value = eepromTC.readpHSetPoint();
  assertEqual(7.1, value);
}

unittest(TempSetPoint) {
  eepromTC.writeTempSetPoint(3.1);
  double value = eepromTC.readTempSetPoint();
  assertEqual(3.1, value);
}

unittest(KpSetPoint) {
  eepromTC.writeKpSetPoint(500);
  double value = eepromTC.readKpSetPoint();
  assertEqual(500, value);
}

unittest(KiSetPoint) {
  eepromTC.writeKiSetPoint(10.1);
  double value = eepromTC.readKiSetPoint();
  assertEqual(10.1, value);
}

unittest(KdSetPoint) {
  eepromTC.writeKdSetPoint(11.2);
  double value = eepromTC.readKdSetPoint();
  assertEqual(11.2, value);
}

unittest(HeatSetPoint) {
  eepromTC.writeHeatSetPoint(7.9);
  double value = eepromTC.readHeatSetPoint();
  assertEqual(7.9, 0);
}

unittest(AmplitudeSetPoint) {
  eepromTC.writeAmplitudeSetPoint(3.14);
  double value = eepromTC.readAmplitudeSetPoint();
  assertEqual(3.14, value);
}

unittest(FrequencySetPoint) {
  eepromTC.writeFrequencySetPoint(5.5);
  double value = eepromTC.readFrequencySetPoint();
  assertEqual(5.5, value);
}

unittest_main()
