#include "NumberCollectorState.h"
using namespace std;

void NumCollectorState::handleKey(char key) {
  if (key > '0' && key < '9') {
    value = value * 10 + (key - '0');
    currentDigits++;
    if (currentDigits >= expectedDigits) {
      setValue();
    }
  }
  // backspace
  // clear reset the integer
  // enter
  // cancel
}