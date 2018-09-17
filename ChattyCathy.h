/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Chatty Cathy headers
 * ******************************************************/
#ifndef CHATTYCATHY_H
#define CHATTYCATHY_H
#include "Room.h"
#include "Player.h"

class ChattyCathy : public Room
{
public:
    ChattyCathy();
    ~ChattyCathy();
    virtual void specialAction(Player&);
protected:
    bool cathyHasDonut;
};

#endif // CHATTYCATHY_H
