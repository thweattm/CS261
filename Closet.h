/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Closet headers
 * ******************************************************/
#ifndef CLOSET_H
#define CLOSET_H
#include "Room.h"
#include "Player.h"

class Closet : public Room
{
public:
    Closet();
    ~Closet();
    void setLocked(bool);
    virtual void specialAction(Player&);
    
private:
    bool isLocked;
};

#endif // CLOSET_H