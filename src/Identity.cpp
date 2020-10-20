#include <Identity.h>
#include <Arduino.h>
#include <EEPROM.h>
#include <WiFiManager.h>
#include "ESP8266mDNS.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

WiFiManager wifiManager;
WiFiClient espClient;
ESP8266WebServer server(80);

String _tipoDisp = "";
String _idMqtt = "";
String _macAddress = "";

void registerDisp(String id){
    EEPROM.begin(150);
    EEPROM.put(90, id);
    EEPROM.put(120, true);
    EEPROM.end();
}

void reconhecimento() {
    Serial.println ("UM CLIENTE");
    server.send(200, "text/html", _tipoDisp);
}

void novoDispositivo() {
  if (server.hasArg("defineID")) {
    String id_value = server.arg("defineID");

    server.send(200, "text/html", id_value);

    registerDisp(id_value);

    delay(500);

    ESP.restart();
  }
}

Identity::Identity(String tipoDisp){
    _tipoDisp = tipoDisp;
}

void Identity::resetDisp(){
    wifiManager.resetSettings();
    ESP.reset();
}

bool Identity::isRegistered(){
    bool status = false;
    EEPROM.begin(150);
    EEPROM.get(120, status);
    EEPROM.end();
    if (status == true && status != 255) {
        return status;
    } else {
        return false;
    }
}

void Identity::configMode(){
    byte mac[6];
    WiFi.macAddress(mac); // Pegando o endMAC e transformando em string
    String macAtual = String(mac[5], HEX);
    //macAtual += ":";
    macAtual += String(mac[4], HEX);
    //macAtual += ":";
    macAtual += String(mac[3], HEX);
    //macAtual += ":";
    macAtual += String(mac[2], HEX);
    //macAtual += ":";
    macAtual += String(mac[1], HEX);
    //macAtual += ":";
    macAtual += String(mac[0], HEX);
    wifiManager.autoConnect(macAtual.c_str());
    _macAddress = macAtual;


    if (!isRegistered()){

        if (!MDNS.begin(_macAddress)) { // Seta Mdns para acessar o dispositivo
            Serial.println("Error setting up MDNS responder!");
            //mdns.register(macAtual);
            while (1) {
                delay(1000);
            }
        }

        server.on("/response", reconhecimento);
        server.on("/", reconhecimento);               // Retorna a info de config inicial
        server.on("/id/", HTTP_GET, novoDispositivo); // Quando o servidor recebe uma requisição com /id/ no corpo da string ele roda a função novoDispositivo
        server.begin();

        while (true) {
            server.handleClient();
        }

    } else {
        EEPROM.begin(150);
        EEPROM.get(90, _idMqtt);
        EEPROM.end();
    }
}

