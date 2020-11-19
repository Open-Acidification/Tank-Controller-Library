/**
 *  This class is for the Serial Commands used in Tank Controller.
 *  Serial here mostly deals with writing or printing data over through the serial port.
 *  Serial.print and Serial.write can be called in different ways to print data.
 *  Also print_PID, print_DataTime, print_mac are used to print the PID information,
 *  current date information, and the mac address.
 */
#include <Arduino.h>
#include <RTClib.h>

class Serial_TC {
public:
  static Serial_TC* instance();
  void print_PID(double Kp, double Ki, double Kd, double output);
  void print_DateTime(DateTime dateTime);
  void print_mac(byte mac[]);
  void print(String aString, String aString2);
  void print(String aString, int anInt);
  void print(String aString, int anInt, int format);
  void print(String aString) {
    Serial.println(aString);
  }
  void write(byte aByte) {
    Serial.write(aByte);
  }
  void write(char arr[], int anInt) {
    Serial.write(arr, anInt);
  }

private:
  Serial_TC() {
    Serial.begin(9600);
  }
  void print_two_digits(int value);
  static Serial_TC* _instance;
};
