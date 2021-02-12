#include "Devices/EEPROM_TC.h"

//  class variables
EEPROM_TC* EEPROM_TC::_instance = nullptr;

//  class methods
/**
 * accessor for singleton
 */
EEPROM_TC* EEPROM_TC::instance() {
  if (!_instance) {
    _instance = new EEPROM_TC();
  }
  return _instance;
}

//  instance methods
/**
 * Constructor sets pins, dimensions, and shows splash screen
 */
EEPROM_TC::EEPROM_TC() {
}

double EEPROM_TC::getPH() {
  return EEPROM.read(PH_ADDRESS);
}

double EEPROM_TC::setPH(double value) {
  EEPROM.update(PH_ADDRESS, value);
}
