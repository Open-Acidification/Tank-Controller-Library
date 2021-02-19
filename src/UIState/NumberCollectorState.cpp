#include "NumberCollectorState.h"

#include <math.h>

#include "MainMenu.h"
using namespace std;

void NumCollectorState::handleKey(char key) {
  if (key > '0' && key < '9') {  // a digit
    value = value * 10 + (key - '0');
    currentDigits++;
    if (currentDigits >= expectedDigits) {
      setValue();
    }
  } else if (key == '-') {  // backspace
    value = floor(value / 10);
  } else if (key == '/') {  // clear
    value = 0;
  } else if (key == '+') {  // enter
    value = value * pow(10, (expectedDigits - currentDigits));
    setValue();
  } else if (key == '*') {  // cancel
    changeState((UIState*)new MainMenu);
  }
}