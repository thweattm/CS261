/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Break Room Definitions
 * ******************************************************/
#include "BreakRoom.h"
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
BreakRoom::BreakRoom()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    donutIsHere = true;
    roomName = "the break room. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
BreakRoom::~BreakRoom()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of the Break Room
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void BreakRoom::specialAction(Player &p)
{
    if (donutIsHere = true)
    {
        std::cout << "You spot a box of donuts on the table. ";
        //Ask if you want to take the donut
        if (p.getDonut())
            donutIsHere = false;
        std::cout << "You quickly leave." << std::endl;
    }
    else
    {
        std::cout << "You notice the box of donuts is empty. The Donut Gremlins must have torn through here. " << std::endl;
    }
}
