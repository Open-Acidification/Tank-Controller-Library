#include <TempProbe_TC.h>

#include "Arduino.h"
#include "ArduinoUnitTests.h"

unittest(TempProbe_Test) {
  // Instance
  TempProbe_TC* tempProbe = TempProbe_TC::instance();

  // Test getResistance()
  uint16_t testRTD = tempProbe->getResistance();
  assertEqual(0, testRTD);

  // Test getTemperature()
  float testTemp = tempProbe->getTemperature();
  assertEqual(-242, (int)testTemp);

  // Test readFault()
  uint8_t testFault = tempProbe->readFault();
  assertEqual(0, testFault);

  // Test clearFault()
  tempProbe->clearFault();
  testFault = tempProbe->readFault();
  assertEqual(0, testFault);

  // Test setTemperature()
  float temp = 0.0;
  tempProbe->setTemperature(0);
  assertEqual(7621, tempProbe->getResistance());
  temp = tempProbe->getTemperature();
  assertTrue(-0.1 < temp && temp < 0.1);

  tempProbe->setTemperature(10);
  assertEqual(7918, tempProbe->getResistance());
  temp = tempProbe->getTemperature();
  assertTrue(9.9 < temp && temp < 10.1);

  tempProbe->setTemperature(90);
  assertEqual(10266, tempProbe->getResistance());
  temp = tempProbe->getTemperature();
  assertTrue(89.9 < temp && temp < 90.1);

  tempProbe->setTemperature(100);
  assertEqual(10554, tempProbe->getResistance());
  temp = tempProbe->getTemperature();
  assertTrue(99.9 < temp && temp < 100.1);
}

unittest_main()
