/*
    Wiser.cpp
*/

#include <Arduino.h>
#include "Wiser.h"

Wiser::Wiser()
{
    WiFiUDP _transport;
}

void Wiser::begin(short port)
{
    _port = port;
    _transport.begin(_port);
}

void Wiser::write(const unsigned char *message)
{
    _transport.beginPacket(_transport.remoteIP(), _transport.remotePort());
    _transport.write(message, 5);
    Serial.println((char *)message);
    Serial.println(_transport.remoteIP());
    Serial.println(_transport.remotePort());
    _transport.endPacket();
}

int Wiser::available()
{
    return _transport.parsePacket();
}

void Wiser::read()
{
    int len = _transport.read(data, 128);
    if (len > 0)
        data[len] = 0;
}