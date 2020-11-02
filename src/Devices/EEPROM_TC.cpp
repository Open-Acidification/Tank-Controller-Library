
#include "EEPROM_TC.h"

void EEPROM_TC::writeMacAddress(byte mac[]) {
  // Store MAC address in EEPROM
  if (EEPROM.read(44) == '#') {
    for (int i = 3; i < 6; i++) {
      mac[i] = EEPROM.read(i + 44);
    }
    Serial.println(F("MAC Address found in EEPROM and read"));
  } else {
    Serial.println(F("No MAC Address Found in EEPROM. Generating New MAC."));
    for (int i = 3; i < 6; i++) {
      mac[i] = TrueRandom.randomByte();
      EEPROM.write(i + 44, mac[i]);
    }
    EEPROM.write(44, '#');
  }
}

void EEPROM_TC::writepHSetPoint(double value) {
  if (ph_set != EepromReadDouble(PH_ADDRESS)) {
    EepromWriteDouble(PH_ADDRESS, ph_set);
  }
}

double EEPROM_TC::readTempSetPoint() { 
  // Load from EEPROM
  ph_set = EepromReadDouble(PH_ADDRESS);
  temp_set = EepromReadDouble(TEMP_ADDRESS);
  Kp = EepromReadDouble(KP_ADDRESS);
  Ki = EepromReadDouble(KI_ADDRESS);
  Kd = EepromReadDouble(KD_ADDRESS);
  heat = EepromReadDouble(HEAT_ADDRESS);
  amplitude = EepromReadDouble(AMPLITUDE_ADDRESS);
  frequency = EepromReadDouble(FREQUENCY_ADDRESS);
  // Use defaults if EEPROM values are invalid
  if (isnan(ph_set)) {
    ph_set = 8.1;
  }
  if (isnan(temp_set)) {
    temp_set = 20;
  }
  if (isnan(Kp)) {
    Kp = 100000;
  }
  if (isnan(Ki)) {
    Ki = 0;
  }
  if (isnan(Kd)) {
    Kd = 0;
  }
  if (isnan(heat)) {
    heat = 0;
  }
  if (isnan(amplitude)) {
    amplitude = 0;
  }
  if (isnan(frequency)) {
    frequency = 0;
  }
}

void EEPROM_TC::doubleWrite(int address, double value) {
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    EEPROM.write(address++, *p++);
  }
}

double EEPROM_TC::doubleRead(int address) {
  double value = 0.0;
  byte* p = (byte*)(void*)&value;
  for (int i = 0; i < sizeof(value); i++) {
    *p++ = EEPROM.read(address++);
  }
  return value;
}
