// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

#include <WiFi.h>
#include <Arduino.h>

#include "test.h"

void notFoundError(WiFiClient);

String ssid = "ShirazU-CSE";
String password = "shirazu1397";
WiFiServer server(80);

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(" . ");
    delay(500);
  }

  Serial.println();
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop()
{
  if (server.hasClient())
  {
    WiFiClient client = server.available();
    while (!client.available())
      ;
    String request = client.readString();
    if (request.indexOf("favicon") > -1)
      notFoundError(client);
    else
    {
      // ### Board LED ###
      if (request.indexOf("led/on") > -1)
      {
        Serial.println("led on");
        digitalWrite(2, 1);
      }
      if (request.indexOf("led/off") > -1)
      {
        Serial.println("led off");
        digitalWrite(2, 0);
      }
      //
      Serial.println(request);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println("Connection: close");
      client.println();
      // client.println("<html><title>reza hesami</title><body>Hello world!led/on</body></html>");
      client.println(htmlFile);
      client.println();
    }
  }
}

void notFoundError(WiFiClient client)
{
  client.println("HTTP/1.1 404 Not Found");
  client.println("Connection: close");
  client.println();
}
