#pragma once

#include <Arduino.h>
#ifdef MOCK_PINS_COUNT
#include <SD_CI.h>
#else
#include <SD.h>
#endif

class SDClass_TC : public SDClass {
public:
  // class methods
  static SDClass_TC* instance();
  // instance methods
  void printRootDirectory();
  // bool begin(uint8_t csPin = SD_CHIP_SELECT_PIN);
  // bool begin(uint32_t clock, uint8_t csPin);

private:
  // class variables
  static SDClass_TC* _instance;

  // instance methods
  SDClass_TC();
  void printDirectory(File dir, int numTabs);
};
