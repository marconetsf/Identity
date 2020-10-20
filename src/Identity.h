#ifndef _IDENTITY_H
#define _IDENTITY_H

#include <Arduino.h>
#include <EEPROM.h>

class Identity{

private:
    /* data */
public:
    Identity(String tipoDisp);
    //void registerDisp(String id);
    void resetDisp();
    void configMode();
};


#endif