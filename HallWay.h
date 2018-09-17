/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Hall Way Headers
 * ******************************************************/
#ifndef HALLWAY_H
#define HALLWAY_H
#include "Room.h"
#include "Player.h"

class HallWay : public Room
{
public:
    HallWay();
    ~HallWay();
    virtual void specialAction(Player&);
};

#endif // HALLWAY_H
