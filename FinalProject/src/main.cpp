#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define ldrPin 3

const String ssid = "AliMaher";
const String password = "nore1939";
const char *brokerAddress = "mqtt.myselfgram.com";
bool isAutoMode = true;

WiFiClient espClient;
PubSubClient client(espClient);

// declare functions
int getLDRValue();

void setupInternetConnection()
{
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");
  Serial.println("IP address : " + WiFi.localIP().toString());
}

void setupMQTTConnection()
{
  static unsigned long previousTime = 0;

  unsigned long currentTime = millis();
  if (currentTime - previousTime > 1000)
  {
    previousTime = currentTime;
    Serial.println("Connecting to MQTT Broker...");
    if (client.connect("ESP32ClientAliMatin1"))
    {
      Serial.println("Connected to MQTT Broker!");
      client.subscribe("esp32/microProject/AliMatin/gate");       // topic
      client.subscribe("esp32/microProject/AliMatin/automation"); // topic
      return;
    }
    else
    {
      Serial.println("Connection to MQTT Broker failed...");
      Serial.println(client.state());
      Serial.println("Retrying in 1 second...");
    }
  }
}

void publishMessage(String topic, String message)
{
  char topicCharArray[60];
  char messageCharArray[120];
  topic.toCharArray(topicCharArray, 60);
  message.toCharArray(messageCharArray, 120);
  client.publish(topicCharArray, messageCharArray);
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  payload[length] = 0;
  String messageStr = String((char *)payload);

  if (String(topic).equals("esp32/microProject/AliMatin/gate"))
  {
    Serial.println(messageStr);
    if (!isAutoMode)
    {

      if (messageStr.equals("open"))
      {
        digitalWrite(18, HIGH);
        // publishMessage("esp32/microProject/AliMatin/gate", "Gate is opening...");
      }
      else if (messageStr.equals("close"))
      {
        digitalWrite(18, LOW);
        // publishMessage("esp32/microProject/AliMatin/gate", "Gate is closing...");
      }
      // else
      // {
      //   Serial.println("Unknown message!");
      //   // publishMessage("esp32/microProject/AliMatin/gate", "Unknown message!");
      // }
    }
  }

  if (String(topic).equals("esp32/microProject/AliMatin/automation"))
  {
    if (messageStr.equals("auto"))
    {
      isAutoMode = true;
      Serial.println("auto");
    }
    else if (messageStr.equals("manual"))
    {
      Serial.println("manual");
      isAutoMode = false;
    }
  }
}

void setup()
{
  pinMode(18, OUTPUT);
  Serial.begin(115200);
  setupInternetConnection();
  client.setServer(brokerAddress, 2329);
  client.setCallback(callback);
}

static unsigned long previousTime = 0;
// unsigned long currentTime = millis();

void loop()
{
  unsigned long currentTime = millis();
  int lightPercentages = getLDRValue();
  // Serial.println(lightPercentages);
  if (currentTime - previousTime > 1000)
  {
    previousTime = currentTime;
    publishMessage("esp32/microProject/AliMatin/ldr", String(lightPercentages));
  }
  if (!client.connected())
  {
    setupMQTTConnection();
  }
  else
  {
    client.loop();
  }

  if (isAutoMode)
  {
    if (lightPercentages < 30)
    {
      digitalWrite(18, HIGH);
    }
    else if (lightPercentages > 70)
    {
      digitalWrite(18, LOW);
    }
  }
}

int getLDRValue()
{
  int ldrValue = analogRead(ldrPin);
  return ldrValue * 100 / 4095.0;
}