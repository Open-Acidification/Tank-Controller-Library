/**
 * PHCalibration.h
 *
 * pH One-Point Calibration
 */
#pragma once
#include "UIState.h"

class PHCalibration : public UIState {
public:
  PHCalibration(TankControllerLib* tc) : UIState(tc) {
  }
  void handleKey(char key);
  const String name() {
    return "PHCalibration";
  }
  const char* prompt() {
    return "pH-Calibration  ";
  };
};
