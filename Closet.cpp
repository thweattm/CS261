/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Closet definitions
 * ******************************************************/
#include "Closet.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Closet::Closet()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    roomName = "the closet. ";
    setLocked(true);
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Closet::~Closet()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: setLocked
** Description: Simple function to set the isLocked bool
** Parameters: Passes in bool
** Pre-Conditions: isLocked
** Post-Conditions: isLocked becomes the parameter
*********************************************************************/
void Closet::setLocked(bool l){isLocked = l;}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of the Closet
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void Closet::specialAction(Player &p)
{
    char input;
    //If the cabinet is locked
    if (isLocked)
    {
        //If you HAVE the key
        if (p.doYouHaveKey())
        {
            setLocked(false);
            std::cout << "Lucky You! You have the key! You open the cabinet ";
            std::cout << "and see the toilet paper. " << std::endl;
            p.getTP();
            std::cout << "You quickly leave." << std::endl;
        }
        
        //If you DO NOT have the key
        else
        {
            std::cout << "You see a locked ";
            std::cout << "cabinet in the corner. If you only had a key ";
            std::cout << "to open it. But wait! You see a crowbar in the other corner. ";
            std::cout << "Would you like to try to pry it open? (y/n)" << std::endl;
            do
            {
                std::cin >> input;
                if (input == 'y')
                {
                    //10% chance to break the lock
                    if (std::rand() % 10 + 1 == 1)
                    {
                        setLocked(false);
                        std::cout << "Your hulk powers have prevailed! You broke the lock! ";
                        std::cout << "Now that the cabinet is open, you see the toilet paper! ";
                        p.getTP();
                        std::cout << "You quickly leave." << std::endl;
                    }
                    //Could not break lock
                    else
                    {
                        std::cout << "You tried with all your might but you were ";
                        std::cout << "unable to break the lock. For fear of an ";
                        std::cout << "\"accident\" you decide not to push your luck. ";
                        std::cout << "You give up and move on in your journey." << std::endl;
                    }
                }
                else
                {
                    std::cout << "You've decided not to attempt to break the lock. ";
                    std::cout << "You hope for the best, and move forward.";
                    std::cout << std::endl;
                }
            } while (input != 'y' && input != 'n');
        }
    }
    
    //Cabinet is NOT locked
    else
    {
        //You already have the TP
        if (p.doYouHaveTP())
        {
            std::cout << "You've already acquired the toilet paper. Hurry up ";
            std::cout << "and get to the bathroom before it's too late!";
            std::cout << std::endl;
        }
        //You don't have the TP
        else
        {
            std::cout << "The cabinet is already unlocked. " << std::endl;
            p.getTP();
            std::cout << "You quickly leave." << std::endl;
        }
    }
}
