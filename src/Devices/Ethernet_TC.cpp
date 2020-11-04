#include "Ethernet_TC.h"
using namespace std;

TC_ethernet *TC_ethernet::_instance = nullptr;

TC_ethernet::TC_ethernet() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Failed to configure Ethernet using DHCP"));
    Ethernet.begin(mac, defaultIP);
    IP = defaultIP;
  }

  defaultIP = IPAddress(192, 168, 1, 2);
  time_serverIP = IPAddress(132, 163, 97, 1);
}

TC_ethernet *TC_ethernet::getInstance() {
  if (_instance == nullptr) {
    _instance = new TC_ethernet;
  }
  return _instance;
}

void TC_ethernet::renewDHCPLease() {
  // unsigned long current_millis = millis();

  // if (current_millis - previous_lease >= LEASE_INTERVAL) {
  Ethernet.maintain();
  // }
}