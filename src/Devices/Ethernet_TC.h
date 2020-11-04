/*
Based off Arduino's Ethernet library
Implements a wrapper for the Ethernet Class
*/

#pragma once

#include "Ethernet.h"

class TC_ethernet {
public:
  static TC_ethernet *getInstance();
  IPAddress getIP() { return IP; };
  void renewDHCPLease();

protected:
  TC_ethernet();

private:
  static TC_ethernet *_instance;
  byte mac[6] = {0x90, 0xA2, 0xDA, 0x00, 0x00, 0x00};
  IPAddress defaultIP;
  IPAddress time_serverIP;
  IPAddress IP;
};
