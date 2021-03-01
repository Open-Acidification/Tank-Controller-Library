/**
 * Abstract superclass for the NumberCollector UI states
 */

#pragma once
#include "UIState.h"

class NumCollectorState : public UIState {
public:
  NumCollectorState(){
      // printPrompt();
  };
  void handleKey(char key);
  virtual void setValue(double value) = 0;
  virtual int getExpectedDigits() = 0;
  virtual const char* getPrompt() = 0;

protected:
  // Helper Functions
  void handleDigit(double digit);
  void backSpace();
  void printPrompt();
  void printValue();
  bool collectedEnoughDigits() {
    return numDigits >= getExpectedDigits();
  }

  double value = 0.0;
  int numDigits = 0;
  int factor = 10;
  bool noDecimal = true;
};

#ifdef MOCK_PINS_COUNT
class TestNumCollectorState : public NumCollectorState {
public:
  // Implementation
  TestNumCollectorState() {
    printPrompt();
  }
  void setValue(double value) {
    storedValue = value;
  }
  int getExpectedDigits() {
    return expectedDigits;
  }
  const char* getPrompt() {
    return "Test:";
  }

  // Testing
  void setExpectedDigits(int value) {
    expectedDigits = value;
  }
  double getValue() {
    return value;
  }
  double getStoredValue() {
    return storedValue;
  };

private:
  double storedValue = 0.0;
  int expectedDigits = 0;
};
#endif
