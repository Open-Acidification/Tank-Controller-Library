#include <Arduino.h>
#ifdef MOCK_PINS_COUNT
#include <LiquidCrystal_CI.h>
#else
#include <LiquidCrystal.h>
#endif

class LiquidCrystal_TC : public LiquidCrystal {
public:
  // class methods
  static LiquidCrystal_TC* instance();

private:
  // class variables
  static LiquidCrystal_TC* _instance;

  // instance variables
  // pins used for our LiquidDisplay
  const int RS = 24, EN = 22, D4 = 26, D5 = 28, D6 = 30, D7 = 32;

  // instance methods
  LiquidCrystal_TC();
  void splashScreen();
};
