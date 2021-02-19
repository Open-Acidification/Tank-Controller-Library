#include "NumberCollectorState.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <iostream>

unittest(handleKey) {
  NumCollectorState test(4);
  assertEqual(0, test._getValue());
  test.handleKey('1');
  test.handleKey('2');
  test.handleKey('3');
  test.handleKey('4');
  assertEqual(1234, test._getValue());
}

unittest(backspace) {
  NumCollectorState test(4);
  test.handleKey('1');
  test.handleKey('2');
  test.handleKey('-');
  assertEqual(1, test._getValue());
}

unittest(clear) {
  NumCollectorState test(4);
  test.handleKey('1');
  test.handleKey('2');
  test.handleKey('/');
  assertEqual(0, test._getValue());
}

unittest(enter) {
  NumCollectorState test(4);
  test.handleKey('1');
  test.handleKey('2');
  test.handleKey('+');
  assertEqual(1200, test._getValue());
}

unittest_main()
