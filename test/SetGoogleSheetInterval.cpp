#include "SetGoogleSheetInterval.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "EEPROM_TC.h"
#include "TankControllerLib.h"

unittest(test) {
  TankControllerLib* tc = TankControllerLib::instance();
  SetGoogleSheetInterval* test = new SetGoogleSheetInterval(tc);
  tc->setNextState(test, true);

  // setValue
  test->setValue(30);
  assertEqual(30, EEPROM_TC::instance()->getGoogleSheetInterval());

  // during the delay we showed the new value
  std::vector<String> lines = LiquidCrystal_TC::instance()->getLines();
  assertEqual("New interval=30 ", lines[1]);
  assertEqual("Wait", tc->stateName());
  delay(1000);
  tc->loop();
  // now we should be back to the main menu
  assertEqual("MainMenu", tc->stateName());
}

unittest_main()
