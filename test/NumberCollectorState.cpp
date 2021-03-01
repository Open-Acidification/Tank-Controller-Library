#include "NumberCollectorState.h"

#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include <iostream>

unittest(handleDigit_NoDecimal) {
  TestNumCollectorState testNoDecimal;
  testNoDecimal.setExpectedDigits(3);
  assertEqual(0, testNoDecimal.getValue());
  testNoDecimal.handleKey('1');
  testNoDecimal.handleKey('2');
  testNoDecimal.handleKey('3');
  assertEqual(123, testNoDecimal.getValue());
  assertEqual(123, testNoDecimal.getStoredValue());
}

unittest(handleDigit_WithDecimal) {
  TestNumCollectorState testDecimal;
  testDecimal.setExpectedDigits(4);
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('*');
  testDecimal.handleKey('3');
  testDecimal.handleKey('4');
  assertEqual(12.34, testDecimal.getValue());
  assertEqual(12.34, testDecimal.getStoredValue());
}

unittest(handleDigit_MultipleDecimals) {
  TestNumCollectorState testDecimal;
  testDecimal.setExpectedDigits(4);
  testDecimal.handleKey('1');
  testDecimal.handleKey('2');
  testDecimal.handleKey('*');
  testDecimal.handleKey('*');
  testDecimal.handleKey('3');
  testDecimal.handleKey('*');
  testDecimal.handleKey('4');
  assertEqual(12.34, testDecimal.getValue());
  assertEqual(12.34, testDecimal.getStoredValue());
}

unittest(backSpace) {
}

unittest(clear) {
}

unittest(enter) {
}

unittest(printing) {
}

unittest_main()
