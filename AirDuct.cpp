/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: AirDuct definitions
 * ******************************************************/
#include "AirDuct.h"
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign the room's pointers to NULL as well as the room name string
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
AirDuct::AirDuct()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    roomName = "the air duct. ";
}

/*********************************************************************  
** Function: Destructor
** Description: Remove the pointers, assign to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
AirDuct::~AirDuct()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: AirDuct doesn't have much of an "action" but this provides
** the verbiage for the output and description of the area.
** Parameters: Passes in Player reference to keep in line with other room's needs.
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
void AirDuct::specialAction(Player &p)
{
    std::cout << "Where some people would see a wall, you see opportunity. ";
    std::cout << "You've crawled into the air duct in hopes of finding ";
    std::cout << "your destination even sooner than you thought possible. ";
    std::cout << "You're not sure what direction goes where, ";
    std::cout << "but you're taking the risk anyway. " << std::endl;
}
