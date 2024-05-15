#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include <Wiser.h>

Wiser ws;

void setup()
{
	Serial.begin(9600);
	WiFi.begin("JioFiber-T2JA8", "OhShiath3uivuj4i");
	while (WiFi.status() != WL_CONNECTED)
		delay(500);
	Serial.println(WiFi.localIP());

	ws.init();
}

void loop()
{
	ws.write(ws.read());
	delay(1000);
}