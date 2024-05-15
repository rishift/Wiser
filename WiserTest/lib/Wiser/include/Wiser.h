/*
	Wiser.h - Wireless Serial Monitor for ESPs
	Created by Rishi Vishwakarma, May 2024
*/

#include <Arduino.h>
#include <WiFiUdp.h>

#ifndef Wiser_h
#define Morse_h



class Wiser
{
public:
	Wiser();
	void begin(short);
	void write(const unsigned char *);
	int available();
	char data[128];
	void read();

private:
	WiFiUDP _transport;
	short _port;
	IPAddress _remoteIP;
	short _remotePort;
};

#endif