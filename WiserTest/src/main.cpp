#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include <Wiser.h>

Wiser ws;

void setup()
{
  Serial.begin(9600);
  WiFi.begin("JioFiber-T2JA8", "OhShiath3uivuj4i");
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  ws.begin(5781);
}

void loop()
{
  ws.write((const unsigned char *)"hello");
  delay(1000);

  if (ws.available() > 0)
  {
    ws.read();
    Serial.println(ws.data);
  }
  
}
