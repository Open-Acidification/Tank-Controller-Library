#pragma once
#include "NumberCollectorState.h"

class SetTempSetPoint : public NumCollectorState {
public:
  const char *prompt() {
    return "Set Temperature ";
  };
  int getExpectedDigits() {
    return 3;
  };
  void setValue(double value);
};
