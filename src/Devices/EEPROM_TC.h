#pragma once

#include <Arduino.h>
#include <EEPROM.h>

class EEPROM_TC {
public:
  // class methods
  static EEPROM_TC* instance();

  // accessor methods
  double getPH();

  // setter methods
  double setPH(double value);

private:
  // class variables
  static EEPROM_TC* _instance;

  // instance variables
  const int PH_ADDRESS = 0;

  // instance methods
  EEPROM_TC();
};
