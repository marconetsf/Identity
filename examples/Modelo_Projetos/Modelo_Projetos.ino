#include <Identity.h>

const byte resetPin = D4;   // Pino de reset
#define ledDebug D6         // Led RGB debug

// Modelos de Tópicos de comunicação MQTT
String func1 = "projeto/id/func1"; 
String func2 = "projeto/id/func2";
String func3 = "projeto/id/func3";

Identity dispositivo("Smart_pools");

void setup() {

   dispositivo.configMode();

}

void loop() {
  // put your main code here, to run repeatedly:

}
