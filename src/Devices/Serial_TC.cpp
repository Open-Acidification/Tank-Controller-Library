#include "Devices/Serial_TC.h"

/**
 * static variable for singleton
 */
Serial_TC* Serial_TC::_instance = nullptr;

/**
 * static member function to return singleton
 */
Serial_TC* Serial_TC::instance() {
  if (!_instance) {
    _instance = new Serial_TC();
  }
  return _instance;
}

/**
 * private function to add a leading zero digit
 */
void Serial_TC::print_two_digits(int value) {
  if (value < 10) {
    Serial.print('0');
  }
  Serial.print(value, DEC);
}

/**
 * Print the PID constants and output
 */
void Serial_TC::print_PID(double Kp, double Ki, double Kd, double output) {
  Serial.print(F("Kp:"));
  Serial.print(Kp);
  Serial.print(F(" Ki:"));
  Serial.print(Ki);
  Serial.print(F(" Kd:"));
  Serial.println(Kd);
  Serial.print(F("PID output (s): "));
  Serial.println(output / 1000, 1);
}

void Serial_TC::print_DateTime(DateTime dateTime) {
  Serial.print(dateTime.year(), DEC);
  Serial.print('-');
  print_two_digits(dateTime.month());
  Serial.print('-');
  print_two_digits(dateTime.day());
  Serial.print(' ');
  print_two_digits(dateTime.hour());
  Serial.print(':');
  print_two_digits(dateTime.minute());
  Serial.print(':');
  print_two_digits(dateTime.second());
  Serial.println();
}

void Serial_TC::print_mac(byte mac[]) {
  Serial.print(F("MAC Address: "));
  Serial.print(mac[0]);
  for (int i = 1; i < 6; ++i) {
    Serial.print(':');
    Serial.print(mac[i]);
  }
  Serial.println();
}

void Serial_TC::print(String aString, String aString2) {
  Serial.println(aString);
  Serial.println(aString2);
}

void Serial_TC::print(String aString, int anInt) {
  Serial.print(aString);
  Serial.println(anInt);
}

void Serial_TC::print(String aString, int anInt, int format) {
  Serial.print(aString);
  Serial.println(anInt, format);
}
