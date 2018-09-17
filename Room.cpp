/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Room Definitions
 * ******************************************************/
#include "Room.h"
#include  <cstdlib>

/*********************************************************************  
** Function: getRoomname
** Description: Return the string for the room name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return roomName
*********************************************************************/
std::string Room::getRoomname(){return roomName;}

/*********************************************************************  
** Function: setPointers
** Description: Set each room's pointers for the 4 directions to other rooms
** Parameters: 4 rooms passed as pointer references
** Pre-Conditions: 4 rooms
** Post-Conditions: Assign the 4 rooms to their respective directions
*********************************************************************/
void Room::setPointers(Room *&l, Room *&r, Room *&s, Room *&b)
{
    left = l;
    right = r;
    straight = s;
    back = b;
}

/*********************************************************************  
** Function: checkDirection
** Description: Check the direction that the user requested to see if it's NULL or assigned
** Parameters: int d = the direction the user inputs from the menu
** Pre-Conditions: N/A
** Post-Conditions: Returns true/false if it's valid/invalid
*********************************************************************/
bool Room::checkDirection(int d)
{
    switch (d){
        //Check left
        case 1:
                if (this->left != NULL)
                    return true;
                else
                    return false;
        //Check right
        case 2:
                if (this->right != NULL)
                    return true;
                else
                    return false;
        //Check straight
        case 3:
                if (this->straight != NULL)
                    return true;
                else
                    return false;
        //Check back
        case 4:
                if (this->back != NULL)
                    return true;
                else
                    return false;
        //Default
        default:
                return false;
    };
}

/*********************************************************************  
** Function: moveDirection
** Description: If the checkDirection function above determines true, this
** will make the move as requested by the user.
** Parameters: cr = currentroom to reassign the current room pointer, and int d
** which is the option the user chose from the menu.
** Pre-Conditions: Current room is assigned
** Post-Conditions: If valid, will return true or false and reassign current room
*********************************************************************/
bool Room::moveDirection(Room *&cr, int d)
{
    if (checkDirection(d))
    {
        switch (d)
        {
            case 1: cr = this->left;
                    return true;
            case 2: cr = this->right;
                    return true;
            case 3: cr = this->straight;
                    return true;
            case 4: cr = this->back;
                    return true;
        };
    }
    else
        return false;
}
