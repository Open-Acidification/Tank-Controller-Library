#include "NumberCollectorState.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <iostream>

// test to see if it collects digits
unittest(handleKey) {
  NumCollectorState test(4);
  assertEqual(0, test._getValue());
  test.handleKey('1');
  test.handleKey('2');
  test.handleKey('3');
  test.handleKey('4');
  assertEqual(1234, test._getValue());
}

unittest_main()