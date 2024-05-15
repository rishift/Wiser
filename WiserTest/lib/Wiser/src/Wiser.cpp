/*
    Wiser.cpp
*/

#include <Arduino.h>
#include "Wiser.h"

Wiser::Wiser()
{
    WiFiUDP _transport;
}

void Wiser::init()
{
    _transport.begin(WISER_PORT);
}

void Wiser::write(char *message, bool newline = true)
{
    _transport.beginPacket(_transport.remoteIP(), _transport.remotePort());
    _transport.write((const unsigned char *)message, sizeof message);
    if (newline)
        _transport.write('\n');
    _transport.endPacket();
}

char *Wiser::read()
{
    if (!_transport.parsePacket())
        return 0;

    int len = _transport.read(_data, WISER_BUFFERSIZE);
    if (len > 0)
        _data[len] = 0;
    return _data;
}