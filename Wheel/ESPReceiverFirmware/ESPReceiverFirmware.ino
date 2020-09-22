#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>

#define APSSID "SimInput"
#define APPSK  "12345678"
#define PACKET_SIZE 9

const char *ssid = APSSID;
const char *password = APPSK;
unsigned int localUdpPort = 4210;
byte incomingPacket[9];

WiFiUDP Udp;

void setup() {
  delay(1000);
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Udp.begin(localUdpPort);
  SPI.begin();
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) //non blocking
  {
    int len = Udp.read(incomingPacket, PACKET_SIZE);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    for (int i = 0; i < sizeof(incomingPacket); i++) {
      SPI.transfer(incomingPacket[i]);
    }
  }
}
