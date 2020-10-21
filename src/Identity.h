#ifndef _IDENTITY_H
#define _IDENTITY_H

#include <Arduino.h>

class Identity{

private:
void registerDisp(String id);
    // void reconhecimento();
    // void novoDispositivo();
    bool isRegistered();
public:
    Identity(String tipoDisp);
    void resetDisp();
    void configMode();
    String getID(); 
    String getMAC();
    String setTopic(String topic);

    
};


#endif