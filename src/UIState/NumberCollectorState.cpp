#include "NumberCollectorState.h"

#include <math.h>

#include <iostream>

#include "MainMenu.h"

void NumCollectorState::handleKey(char key) {
  if (key > '0' && key < '9') {  // a digit
    numDigits++;
    handleDigit(key - '0');
    if (collectedEnoughDigits()) {
      std::cout << "Has enough digits, Value = " << value << std::endl;
      setValue(value);
    }
  } else if (key == 'B') {  // Backspace
    backSpace();
  } else if (key == 'C') {  // Clear the value
    value = 0;
  } else if (key == 'A') {  // All done
    setValue(value);
  } else if (key == 'D') {  // Don't finish
    changeState((UIState*)new MainMenu);
  } else if (key == '*') {  // Decimal place (if we already have a decimal nothing happens)
    noDecimal = false;
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
}

void NumCollectorState::printValue() {
}
