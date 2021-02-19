/**
 * Abstract superclass for the NumberCollector UI states
 */

#pragma once
#include "UIState.h"

class NumCollectorState : UIState {
public:
  NumCollectorState(int digits) {
    expectedDigits = digits;
  }
  void handleKey(char key);
  void setValue(){};

  // For testing
  int _getValue() {
    return value;
  };

protected:
  int value = 0;
  int currentDigits = 0;
  int expectedDigits;
};
