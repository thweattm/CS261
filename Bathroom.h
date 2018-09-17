/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Bathroom headers
 * ******************************************************/
#ifndef BATHROOM_H
#define BATHROOM_H
#include "Room.h"
#include "Player.h"

class Bathroom : public Room
{
public:
    Bathroom();
    ~Bathroom();
    virtual void specialAction(Player&);
};

#endif // BATHROOM_H
