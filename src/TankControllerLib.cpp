#include "TankControllerLib.h"

#ifdef MOCK_PINS_COUNT
#include <cassert>
#else
#define assert(p) (void)0
#endif

#include "UIState/MainMenu.h"
#include "UIState/UIState.h"

const char NO_KEY = '\0';   // Move to LiquidCrystal?

// ------------ Class Methods ------------
/**
 * static variable to hold singleton
 */
TankControllerLib* TankControllerLib::_instance = nullptr;

/**
 * static function to return singleton
 */
TankControllerLib* TankControllerLib::instance() {
  if (!_instance) {
    _instance = new TankControllerLib;
  }
  return _instance;
}

// ------------ Instance Methods ------------

/**
 * Constructor
 */
TankControllerLib::TankControllerLib() {
  assert(!_instance);
  _state = nullptr;
  lcd = LiquidCrystal_TC::instance();
}

/**
 * Destructor
 */
TankControllerLib::~TankControllerLib() {
  changeState(nullptr);
  assert(this == _instance);
  _instance = nullptr;
}

/**
 * Blink the on-board LED to let us know that loop() is being called
 * 
 */
void TankControllerLib::blink() {
  if (millis() / 500 % 2) {
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  } else {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  }
}

/**
 * Private member function called by UIState subclasses
 */
void TankControllerLib::changeState(UIState* newState) {
  if (_state) {
    delete _state;
  }
  _state = newState;
}

/**
 * This is one of two public instance functions. 
 * It is called repeatedly while the board is on.
 */
void TankControllerLib::loop() {
  blink();  //  blink the on-board LED to show that we are running
  char key = NO_KEY;  // custom_keypad.getKey();
  if (key != NO_KEY) {
    Serial.print(F("To start key: "));
    Serial.println(key);
    _state->handleKey(key);
  }
}

/**
 * This is one of two public instance functions. 
 * Here we do any one-time startup initialization.
 */
void TankControllerLib::setup() {
  changeState((UIState*)new MainMenu);
  pinMode(LED_BUILTIN, OUTPUT);
}
