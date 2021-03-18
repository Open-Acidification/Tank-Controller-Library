#include "Devices/EEPROM_TC.h"

#include <EEPROM.h>

#include "Devices/EEPROM_TC_2.h"
#include "Devices/EEPROM_TC_3.h"

#ifdef MOCK_PINS_COUNT
#include <cassert>   // to support testing
#include <iostream>  // to support occasional debugging output
#else
#define assert(p) (void)0
#endif

//  class variables
EEPROM_TC* EEPROM_TC::_instance = nullptr;

//  class methods
/**
 * accessor for singleton
 */
EEPROM_TC* EEPROM_TC::instance() {
  if (_instance) {
    return _instance;
  }
  _instance = new EEPROM_TC_3();
  if (_instance->isRightVersion()) {
    return _instance;
  }
  delete _instance;
  _instance = new EEPROM_TC_2();
  return _instance;
}

//  instance methods
double EEPROM_TC::eepromReadDouble(int address) {
  assert(address >= 0);
  double value = 0.0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(address++);
  }
  return value;
}

void EEPROM_TC::eepromWriteDouble(int address, double value) {
  assert(address >= 0);
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    EEPROM.update(address++, *p++);
  }
}

int EEPROM_TC::eepromReadInt(int address) {
  assert(address >= 0);
  int value = 0.0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(address++);
  }
  return value;
}

void EEPROM_TC::eepromWriteInt(int address, int value) {
  assert(address >= 0);
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    EEPROM.update(address++, *p++);
  }
}
