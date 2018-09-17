/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Break Room headers
 * ******************************************************/
#ifndef BREAKROOM_H
#define BREAKROOM_H
#include "Room.h"
#include "Player.h"

class BreakRoom : public Room
{
public:
    BreakRoom();
    ~BreakRoom();
    virtual void specialAction(Player&);
protected:
    bool donutIsHere;
};

#endif // BREAKROOM_H
