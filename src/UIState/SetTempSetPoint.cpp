/**
 * SetTemperatureSetPoint.cpp
 */
#include "SetTempSetPoint.h"

#include "../Devices/EEPROM_TC.h"

void SetTempSetPoint::setValue(double value) {
  EEPROM_TC::instance()->setTemp(value);
}
