/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Your Office headers
 * ******************************************************/
#ifndef YOUROFFICE_H
#define YOUROFFICE_H
#include "Room.h"
#include "Player.h"

class YourOffice: public Room
{
public:
    YourOffice();
    ~YourOffice();
    virtual void specialAction(Player&);
protected:
    bool TPSisHere;
};

#endif // YOUROFFICE_H
