#ifndef _IDENTITY_H
#define _IDENTITY_H

#include <Arduino.h>
#include <EEPROM.h>

class Identity{

private:
    /* data */
public:
    Identity();
    void registerDisp(String id);
    bool isRegistered();
    void resetDisp();
};


#endif