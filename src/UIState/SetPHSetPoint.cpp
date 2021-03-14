/**
 * SetPHSetPoint.cpp
 */

#include "SetPHSetPoint.h"

#include "MainMenu.h"

void SetPHSetPoint::handleKey(char key) {
  switch (key) {
    case 'D':  // Don't save (cancel)
      this->setNextState((UIState *)new MainMenu);
      break;
    default:
      break;
  };
}
