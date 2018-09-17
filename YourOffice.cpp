/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Your Office definitions
 * ******************************************************/
#include "YourOffice.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
YourOffice::YourOffice()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    TPSisHere = true;
    roomName = "your office. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
YourOffice::~YourOffice()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of Your Office
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void YourOffice::specialAction(Player &p)
{
    //TPS Report is in your office
    if (TPSisHere == true)
    {
        std::cout << "You notice the TPS report on your desk. ";
        //Ask if you want to pick it up
        if (p.getTPS())
            TPSisHere = false;
        std::cout << "You quickly leave." << std::endl;
    }
    
    //TPS Report is not in your office
    //Also means you've already been here
    else
    {
        std::cout << "This is the opposite way as the bathroom. Hurry!" << std::endl;
    }
}
