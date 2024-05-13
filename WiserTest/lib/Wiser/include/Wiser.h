/*
	Wiser.h - Wireless Serial Monitor for ESPs
	Created by Rishi Vishwakarma, May 2024
*/

#include <Arduino.h>
#include <WiFiUdp.h>

#ifndef Wiser_h
#define Morse_h

#define PORT 4210

class Wiser
{
public:
	Wiser();
	void begin();
	void write(const unsigned char *message);

private:
	WiFiUDP _transport;
	IPAddress _remoteIP;
	short _remotePort;
};

#endif