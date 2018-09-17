/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Hall way Definitions
 * ******************************************************/
#include "HallWay.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
HallWay::HallWay()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    roomName = "the hallway. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
HallWay::~HallWay()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of the Closet
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void HallWay::specialAction(Player &p)
{
    char input;
    
    //1 in 2 chance the Janitor is in the hallway
    if (std::rand() % 2 + 1 == 1)
    {
        
        //If you already have the key
        if (p.doYouHaveKey())
        {
            std::cout << "You see the janitor again. He asks you how your quest is going. ";
            std::cout << "You let him know you're still working on it, ";
            std::cout << "and head on your way." << std::endl;
        }
        //You don't have the key
        else
        {
            std::cout << "You've spotted the Janitor. He asks you what you're up to. ";
            std::cout << "You fill him in on your objective. He kindly gives you the ";
            std::cout << "heads up that there is NO toilet paper in the bathroom. GASP! ";
            std::cout << "He's busy, but he aks if you would like the key to the ";
            std::cout << "closet so you can get some toilet paper for yourself. ";
            p.getKey();
            std::cout << "You quickly leave." << std::endl;
        }
    }
    
    //Janitor's not in the hallway
    else
    {
        std::cout << "It seems the light has been turned off. ";
        std::cout << "It must have been the janitor. He was just here. ";
        std::cout << "Would you like to turn it back on? (y/n)" << std::endl;
        do
        {
            std::cin >> input;
            if (input != 'y' && input != 'n')
            {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
            else
            {
                if (input == 'y')
                    std::cout << "That's better. You can now see." << std::endl;
                else
                    std::cout << "It's going to be hard to see where you're going." << std::endl;
            }
        } while (input != 'y' && input != 'n');
    }
}
