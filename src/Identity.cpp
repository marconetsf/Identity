#include <Identity.h>
#include <Arduino.h>
#include <EEPROM.h>
#include <WiFiManager.h>

WiFiManager wifiManager; 

Identity::Identity(){
    
}

void Identity::registerDisp(String id){
    EEPROM.begin(150);
    EEPROM.put(90, id);
    EEPROM.put(120, true);
    EEPROM.end();
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

void Identity::resetDisp(){
    wifiManager.resetSettings();
    ESP.reset();
}