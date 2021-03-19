/**
 * SetGoogleSheetInterval.cpp
 */

#include "SetGoogleSheetInterval.h"

#include "../Devices/EEPROM_TC.h"
#include "../Devices/LiquidCrystal_TC.h"

void SetGoogleSheetInterval::setValue(double value) {
  EEPROM_TC::instance()->setGoogleSheetInterval(value);

  char output[17];
  sprintf(output, "New interval=%i", value);
  LiquidCrystal_TC::instance()->writeLine(output, 1);
  delay(1000);  // 1 second
  returnToMainMenu();
}
