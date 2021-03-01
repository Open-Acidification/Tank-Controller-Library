#include "NumberCollectorState.h"

#include <math.h>

#include "../Devices/LiquidCrystal_TC.h"
#include "MainMenu.h"

void NumCollectorState::handleKey(char key) {
  if (key > '0' && key < '9') {  // a digit
    numDigits++;
    handleDigit(key - '0');
    if (collectedEnoughDigits()) {
      setValue(value);
    }
  } else if (key == 'B') {  // Backspace
    numDigits--;
    backSpace();
  } else if (key == 'C') {  // Clear the value
    numDigits = 0;
    value = 0;
  } else if (key == 'A') {  // All done
    setValue(value);
  } else if (key == '*') {  // Decimal place (if we already have a decimal nothing happens)
    noDecimal = false;
  } else if (key == 'D') {  // Don't finish
    changeState((UIState*)new MainMenu);
  }
  printValue();
}

void NumCollectorState::handleDigit(double digit) {
  if (noDecimal) {
    value = value * 10 + digit;
  } else {
    value = value + digit / factor;
    factor = factor * 10;
  }
}

void NumCollectorState::backSpace() {
  if (noDecimal) {
    value = std::floor(value / 10);
  } else {
    factor = factor / 10;
    // we use the factor/10 because we want there to be 1 decimal place to floor
    value = std::floor(value * factor / 10) / (factor / 10);
  }
}

void NumCollectorState::printPrompt() {
  char holder[16];
  strcpy(holder, getPrompt());
  LiquidCrystal_TC::instance()->writeLine(holder, 0);
  strcpy(holder, " ");
  LiquidCrystal_TC::instance()->writeLine(holder, 1);
}

void NumCollectorState::printValue() {
  char strValue[16];
  if (noDecimal) {
    std::sprintf(strValue, "%.*f", 0, value);
  } else if (factor == 10) {
    std::sprintf(strValue, "%.*f.", 0, value);
  } else {
    int precision = std::log10(factor / 10);
    std::sprintf(strValue, "%.*f", precision, value);
  }
  LiquidCrystal_TC::instance()->writeLine(strValue, 1);
}
