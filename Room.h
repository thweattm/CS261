/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Room Headers
 * ******************************************************/
#ifndef ROOM_H
#define ROOM_H
#include "Player.h"
#include <string>

//Room Parent Class
class Room
{
public:
    virtual void specialAction(Player&)=0;
    std::string getRoomname();
    void setPointers(Room *&, Room *&, Room *&, Room *&);
    bool checkDirection(int);
    bool moveDirection(Room *&, int);

protected:
    Room *left;
    Room *right;
    Room *straight;
    Room *back;
    std::string roomName;
};

#endif // ROOM_H
