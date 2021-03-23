#include "SetTempSetPoint.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "EEPROM_TC.h"
#include "TankControllerLib.h"

unittest(test) {
  TankControllerLibTest tc;
  SetTempSetPoint* test = new SetTempSetPoint(&tc);
  tc.setNextState(test);

  // setValue
  test->setValue(50.05);
  assertEqual(50.05, EEPROM_TC::instance()->getTemp());

  // during the delay we showed the new value
  std::vector<String> lines = LiquidCrystal_TC::instance()->getLines();
  assertEqual("New Temp=50.05  ", lines[1]);
  assertEqual("Wait", tc->stateName());
  delay(1000);
  tc.loop();
  // now we should be back to the main menu
  assertEqual("MainMenu", tc->stateName());
}

unittest_main()
