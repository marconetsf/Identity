#include <ESP8266WiFi.h>
#include <Identity.h>
#include <PubSubClient.h>

const byte resetPin = D4;   // Pino de reset
#define ledDebugR D7
#define ledDebugG D6
#define ledDebugB D5

// Modelos de Tópicos de comunicação MQTT
String func1 = "projeto/id/func1";
String func2 = "projeto/id/func2";
String func3 = "projeto/id/func3";

WiFiClient espClient;
PubSubClient client(espClient);
Identity dispositivo("Smart_pools");

void setup() {
  Serial.begin(115200);
  //dispositivo.resetDisp();
  dispositivo.configMode();
  client.setServer("18.230.89.88", 1883);
  client.setCallback(callback);
  Serial.println(dispositivo.getMAC());
  Serial.println(dispositivo.getStrID());
  Serial.println(dispositivo.getCharID());

}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (Serial.available()) {
    if (Serial.read() == 'a') {
      client.publish(dispositivo.setTopic(func1), "roe");
      Serial.println(dispositivo.setTopic(func1));
    }
  }



  //delay(1000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Tentando conexão com broker MQTT");

    if (client.connect(dispositivo.getCharID(), "autocom", "autocom")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 3 segundos...");
      delay(3000);
    }
  }
}
