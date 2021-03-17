/**
 * SetTankID.cpp
 */

#include "SetTankID.h"

#include "../Devices/EEPROM_TC.h"
#include "../Devices/LiquidCrystal_TC.h"

void SetTankID::setValue(double value) {
  EEPROM_TC::instance()->setTankID(value);

  char output[16];
  sprintf(output, "Tank ID=%.2f", value);
  LiquidCrystal_TC::instance()->writeLine(output, 1);
  delay(1000);  // 1 second
  returnToMainMenu();
}
