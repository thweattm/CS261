/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Air Duct headers
 * ******************************************************/
#ifndef AIRDUCT_H
#define AIRDUCT_H
#include "Room.h"
#include "Player.h"

class AirDuct : public Room
{
public:
    AirDuct();
    ~AirDuct();
    virtual void specialAction(Player&);
};

#endif // AIRDUCT_H
