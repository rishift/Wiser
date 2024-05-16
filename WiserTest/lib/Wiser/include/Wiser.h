/*
	Wiser.h - Wireless Serial Monitor for ESPs
	Created by Rishi Vishwakarma, May 2024
*/

#include <Arduino.h>
#include <WiFiUdp.h>

#ifndef Wiser_h
#define Wiser_h

#define WISER_PORT 5781
#define WISER_BUFFERSIZE 128

class Wiser
{
public:
	Wiser();
	void init();
	void write(char *message, bool newline = true);
	char *read();

private:
	WiFiUDP _transport;
	IPAddress _remoteIP;
	uint16_t _remotePort;
	char _data[WISER_BUFFERSIZE];
};

#endif