/**
 * SetTempSetPoint.h
 *
 * Set the target Temperature
 */
#pragma once
#include "NumberCollectorState.h"

class SetTempSetPoint : public NumCollectorState {
public:
  const char *prompt() {
    return "Set Temperature ";
  };
  int getExpectedDigits() {
    return 4;
  };
  void setValue(double value);
};
