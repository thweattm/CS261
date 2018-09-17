/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Bathroom definitions
 * ******************************************************/
#include "Bathroom.h"
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Bathroom::Bathroom()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    roomName = "the bathroom. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Bathroom::~Bathroom()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of the bathroom
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void Bathroom::specialAction(Player &p)
{
    //If you have the TP = mission accomplished, you win!
    if (p.doYouHaveTP())
    {
        std::cout << "You successfully made it to the bathroom AND you have the toilet paper! ";
        std::cout << "Your quest is over. \n\nNow HURRY UP and GET BACK TO WORK!" << std::endl;
        p.setMissionComplete(true);
    }

    //If you don't have the TP
    else
    {
        //If you have the key (you'd already know the TP is out)
        if (p.doYouHaveKey())
        {
            std::cout << "You made it to the bathroom, but you haven't found the toilet paper! ";
            std::cout << "Hurry and find the toilet paper before it's too late!" << std::endl;
        }
        //No TP & No Key
        else
        {
            std::cout << "You made it to the bathroom, however, you're immediately overcome ";
            std::cout << "with fear as you notice there is no toilet paper!" ;
            std::cout << "Hurry and find the toilet paper before it's too late! " << std::endl;
        }
    }
}