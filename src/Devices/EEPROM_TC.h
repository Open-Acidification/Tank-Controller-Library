/*
 * This class provides a wraper for the EEPROM functionality.
 * The EEPROM provides memory whose values are kept when the
 * board is turned off (like a tiny hard drive).
 *
 * This device is used by the tank controller to save configuration information.
 *  - MAC address
 *  - pH set point
 *  - auto-tune parameters
 *  - temperature set point
 *  - load parameters into EEPROM
 *  - Write floating point values
 *  - Read floating point values
 */

#pragma once

#include <Arduino.h>
#include <EEPROM.h>

class EEPROM_TC {
public:
  EEPROM_TC();
  ~EEPROM_TC();
  void getMacAddress(byte mac[]);
  void writeTempSetPoint(double value);
  void writepHSetPoint(double value);
  void writeKpSetPoint(double value);
  void writeKiSetPoint(double value);
  void writeKdSetPoint(double value);
  void writeHeatSetPoint(double value);
  void writeAmplitudeSetPoint(double vlaue);
  void writeFrequencySetPoint(double value);
  double readTempSetPoint();
  double readpHSetPoint();
  double readKpSetPoint();
  double readKiSetPoint();
  double readKdSetPoint();
  double readHeatSetPoint();
  double readAmplitudeSetPoint();
  double readFrequencySetPoint();

private:
  void writeDouble(int address, double value);
  double readDouble(int address, double defaultValue);
  const int PH_ADDRESS = 0;
  const int TEMP_ADDRESS = 4;
  const int TANKID_ADDRESS = 8;
  const int TEMP_CORR_ADDRESS = 12;
  const int KP_ADDRESS = 20;
  const int KI_ADDRESS = 28;
  const int KD_ADDRESS = 36;
  const int MAC_ADDRESS = 44;
  const int HEAT_ADDRESS = 52;
  const int AMPLITUDE_ADDRESS = 56;
  const int FREQUENCY_ADDRESS = 60;
  const int GRANULARITY_ADDRESS = 64;   // granularity for SD logging interval
  const int MAX_DATA_AGE_ADDRESS = 68;  // max data age for SD card
  const int PH_SERIES_SIZE_ADDRESS = 72;
  const int PH_SERIES_POINTER_ADDRESS = 76;
  const int TEMP_SERIES_SIZE_ADDRESS = 80;
  const int TEMP_SERIES_POINTER_ADDRESS = 84;
  const int PH_INTERVAL_ADDRESS = 88;
  const int PH_DELAY_ADDRESS = 92;
  const int TEMP_INTERVAL_ADDRESS = 96;
  const int TEMP_DELAY_ADDRESS = 100;
};
