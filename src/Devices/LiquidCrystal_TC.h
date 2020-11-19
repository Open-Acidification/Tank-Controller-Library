#include <Arduino.h>
#ifdef MOCK_PINS_COUNT
#include <LiquidCrystal_CI.h>
#else
#include <LiquidCrystal.h>
#endif

class LiquidCrystal_TC : public LiquidCrystal {
public:
  static LiquidCrystal_TC* instance();
private:
  LiquidCrystal_TC();
  void splashScreen();
  static LiquidCrystal_TC* _instance;
};
