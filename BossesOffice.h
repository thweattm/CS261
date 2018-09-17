/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Bosses Office headers
 * ******************************************************/
#ifndef BOSSESOFFICE_H
#define BOSSESOFFICE_H
#include "Room.h"
#include "Player.h"

class BossesOffice : public Room
{
public:
    BossesOffice();
    ~BossesOffice();
    virtual void specialAction(Player&);
protected:
    bool bossHasTPS;
};

#endif // BOSSESOFFICE_H
