#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#include <Wiser.h>


WiFiUDP udp;
unsigned int port = 2314;
char data[8];
int size;

Wiser ws;

void setup()
{
  Serial.begin(9600);

  WiFi.begin("rpc", "12345678");

  while (WiFi.status() != WL_CONNECTED)
    delay(500);

  Serial.printf(" ip : %s \n", WiFi.localIP().toString().c_str());
  udp.begin(port);

  ws.begin();

}

void loop()
{
  size = udp.parsePacket();
  if (size)
  {
    Serial.printf("Received %d bytes from %s:%d\n", size, udp.remoteIP().toString().c_str(), udp.remotePort());
    int len = udp.read(data, 8);
     if (len > 0)
    {
      data[len] = 0;
    }
    Serial.printf("contents: %s :", data);
    for (int i = 0; i < len; i++)
    {
      Serial.print(" ");
      Serial.print(data[i]);
    }
    Serial.println();
  }
  
}
