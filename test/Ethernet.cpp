#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "Ethernet_TC.h"

unittest(test) {
  // Test singleton
  Ethernet_TC singleton1;
  singleton1 = singleton1->getInstance();
  Ethernet_TC singleton2;
  singleton2 = singleton2->getInstance();
  assertEqual(singleton1, singleton2);

  // Test that the default Ip was used as a fall back
  assertEqual(singleton->getIP(), "19216812");

  // Test DHCP is being maintained
  singleton1->renewDHCPLease();
  singleton1->renewDHCPLease();
  singleton1->renewDHCPLease();
  assertEqual(singleton1->getNumAttemptedDHCPReleases(), 3);
}

unittest_main()
