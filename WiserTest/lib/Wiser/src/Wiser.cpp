/*
    Wiser.cpp
*/

#include <Arduino.h>
#include "Wiser.h"

Wiser::Wiser()
{
    WiFiUDP _transport;
}

void Wiser::begin()
{
    _transport.begin(PORT);
    char initData[5];
    while (!_transport.parsePacket())
    {
        _transport.read(initData, 5);
        if (initData == "🤝")
        {
            _remoteIP = _transport.remoteIP();
            _remotePort = _transport.remotePort();
            _transport.beginPacket(_remoteIP, _remotePort);
            _transport.write((const uint8_t *)"🤝", 5);
            _transport.endPacket();
        }
    }
}

void Wiser::write(const unsigned char *message)
{

    _transport.beginPacket(_remoteIP, _remotePort);
    _transport.write(message, sizeof message);
    _transport.endPacket();
}