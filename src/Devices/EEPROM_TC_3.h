#pragma once

#include "Devices/EEPROM_TC.h"

class EEPROM_TC_3 : public EEPROM_TC {
public:
  // accessor methods
  double getAmplitude();
  double getCorrectedTemp();
  double getFrequency();
  int getGoogleSheetInterval();
  double getGranularity();
  bool getHeat();
  double getKD();
  double getKI();
  double getKP();
  double getMac();
  double getMaxDataAge();
  double getPH();
  double getPHDelay();
  double getPHInterval();
  double getPHSeriesPointer();
  double getPHSeriesSize();
  int getTankID();
  double getTemp();
  double getTempDelay();
  double getTempInterval();
  double getTempSeriesPointer();
  double getTempSeriesSize();
  int getVersion();

  // setter methods
  void setAmplitude(double value);
  void setCorrectedTemp(double value);
  void setFrequency(double value);
  void setGoogleSheetInterval(int value);
  void setGranularity(double value);
  void setHeat(bool value);
  void setKD(double value);
  void setKI(double value);
  void setKP(double value);
  void setMac(double value);
  void setMaxDataAge(double value);
  void setPH(double value);
  void setPHDelay(double value);
  void setPHInterval(double value);
  void setPHSeriesPointer(double value);
  void setPHSeriesSize(double value);
  void setTankID(int value);
  void setTemp(double value);
  void setTempDelay(double value);
  void setTempInterval(double value);
  void setTempSeriesPointer(double value);
  void setTempSeriesSize(double value);
  void setVersion();

protected:
  virtual bool isRightVersion();

private:
  // new with v0.3
  const int VERSION_ADDRESS = 0;  // 999
  // from v0.197
  // NOTE: addition represents size of previous value
  const int TANK_ID_ADDRESS = VERSION_ADDRESS + 4;  // 999
  const int HEAT_ADDRESS = TANK_ID_ADDRESS + 4;     // bool
  const int PH_ADDRESS = HEAT_ADDRESS + 4;          // 9.999
  const int TEMP_ADDRESS = PH_ADDRESS + 8;          // 99.99
  const int TEMP_CORR_ADDRESS = TEMP_ADDRESS + 8;   // 99.99
  const int KP_ADDRESS = TEMP_CORR_ADDRESS + 8;     // double
  const int KI_ADDRESS = KP_ADDRESS + 8;            // double
  const int KD_ADDRESS = KI_ADDRESS + 8;            // double
  const int MAC_ADDRESS = KD_ADDRESS + 8;           // 8 byte
  // new with v0.2
  const int AMPLITUDE_ADDRESS = MAC_ADDRESS + 8;
  const int FREQUENCY_ADDRESS = AMPLITUDE_ADDRESS + 8;
  const int GRANULARITY_ADDRESS = FREQUENCY_ADDRESS + 8;     // granularity for SD logging interval
  const int MAX_DATA_AGE_ADDRESS = GRANULARITY_ADDRESS + 8;  // max data age for SD card
  const int PH_SERIES_SIZE_ADDRESS = MAX_DATA_AGE_ADDRESS + 8;
  const int PH_SERIES_POINTER_ADDRESS = PH_SERIES_SIZE_ADDRESS + 8;
  const int TEMP_SERIES_SIZE_ADDRESS = PH_SERIES_POINTER_ADDRESS + 8;
  const int TEMP_SERIES_POINTER_ADDRESS = TEMP_SERIES_SIZE_ADDRESS + 8;
  const int PH_INTERVAL_ADDRESS = TEMP_SERIES_POINTER_ADDRESS + 8;
  const int PH_DELAY_ADDRESS = PH_INTERVAL_ADDRESS + 8;
  const int TEMP_INTERVAL_ADDRESS = PH_DELAY_ADDRESS + 8;
  const int TEMP_DELAY_ADDRESS = TEMP_INTERVAL_ADDRESS + 8;
  // new with v0.3
  const int GOOGLE_INTERVAL_ADDRESS = TEMP_DELAY_ADDRESS + 8;
};
