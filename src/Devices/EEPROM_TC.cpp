
#include "EEPROM_TC.h"

void EEPROM_TC::getMacAddress(byte mac[]) {
  // Store MAC address in EEPROM
  if (EEPROM.read(MAC_ADDRESS) == '#') {
    for (int i = 3; i < 6; i++) {
      mac[i] = EEPROM.read(i + MAC_ADDRESS);
    }
    Serial.println(F("MAC Address found in EEPROM and read"));
  } else {
    Serial.println(F("No MAC Address Found in EEPROM. Generating New MAC."));
    for (int i = 3; i < 6; i++) {
      mac[i] = TrueRandom.randomByte();
      EEPROM.write(i + MAC_ADDRESS, mac[i]);
    }
    EEPROM.write(MAC_ADDRESS, '#');
  }
}

double EEPROM_TC::readTempSetPoint() {
  return readDouble(TEMP_ADDRESS, 20);
}

void EEPROM_TC::writeTempSetPoint(double value) {
  writeDouble(TEMP_ADDRESS, value);
}

double EEPROM_TC::readpHSetPoint() {
  return readDouble(PH_ADDRESS, 8.1);
}

void EEPROM_TC::writepHSetPoint(double value) {
  writeDouble(PH_ADDRESS, value);
}

double EEPROM_TC::readKpSetPoint() {
  return readDouble(KP_ADDRESS, 100000);
}

void EEPROM_TC::writeKpSetPoint(double value) {
  writeDouble(KP_ADDRESS, value);
}

double EEPROM_TC::readKiSetPoint() {
  return readDouble(KI_ADDRESS, 0);
}

void EEPROM_TC::writeKiSetPoint(double value) {
  writeDouble(KP_ADDRESS, value);
}

double EEPROM_TC::readKdSetPoint() {
  return readDouble(KD_ADDRESS, 0);
}

void EEPROM_TC::writeKdSetPoint(double value) {
  writeDouble(KD_ADDRESS, value);
}

double EEPROM_TC::readHeatSetPoint() {
  return readDouble(HEAT_ADDRESS, 0);
}

void EEPROM_TC::writeHeatSetPoint(double value) {
  writeDouble(HEAT_ADDRESS, value);
}

double EEPROM_TC::readAmplitudeSetPoint() {
  return readDouble(AMPLITUDE_ADDRESS, 0);
}

void EEPROM_TC::writeAmplitudeSetPoint(double vlaue) {
  writeDouble(AMPLITUDE_ADDRESS, value);
}

double EEPROM_TC::readFrequencySetPoint() {
  return readDouble(FREQUENCY_ADDRESS, 0);
}

void EEPROM_TC::writeFrequencySetPoint(double value) {
  writeDouble(FREQUENCY_ADDRESS, value);
}

void EEPROM_TC::writeDouble(int address, double value) {
  if (value != readDouble(address)) {
    byte* p = (byte*)(void*)&value;
    for (int i = 0; i < sizeof(value); i++) {
      EEPROM.write(address++, *p++);
    }
  }
}

double EEPROM_TC::readDouble(int address, double default) {
  double value = 0.0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(address++);
  }
  return isnan(value) ? default : value;
}
