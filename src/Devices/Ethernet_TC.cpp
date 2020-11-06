#include "Ethernet_TC.h"

Ethernet_TC *Ethernet_TC::_instance = nullptr;

// Establishes the Ethenet connection and sets class variables
Ethernet_TC::Ethernet_TC() {
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Failed to configure Ethernet using DHCP"));
    IPAddress defaultIP = IPAddress(192, 168, 1, 2);
    Ethernet.begin(mac, defaultIP);
    IP = defaultIP;
  }
}

Ethernet_TC *Ethernet_TC::getInstance() {
  if (_instance == nullptr) {
    _instance = new Ethernet_TC;
  }
  return _instance;
}

void Ethernet_TC::renewDHCPLease() {
  unsigned long current_millis = millis();

  if (current_millis - previous_lease >= LEASE_INTERVAL) {
    Ethernet.maintain();
    previous_lease = current_millis;
  }

  numAttemptedDHCPReleases++;
}
