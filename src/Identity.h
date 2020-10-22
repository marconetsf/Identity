#ifndef _IDENTITY_H
#define _IDENTITY_H

#include <Arduino.h>

class Identity{

private:
void registerDisp(String id);
    // void reconhecimento();
    // void novoDispositivo();
    bool isRegistered();
    void callback(char* topic, byte* payload, unsigned int length);
public:
    Identity(String tipoDisp);
    void resetDisp();
    void configMode();
    String getStrID();
    char* getCharID(); 
    String getMAC();
    char* setTopic(String topic);
};

#endif