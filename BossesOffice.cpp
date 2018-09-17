/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Bosses Office definitions
 * ******************************************************/
#include "BossesOffice.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
BossesOffice::BossesOffice()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    bossHasTPS = false;
    roomName = "the Bosses Office. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
BossesOffice::~BossesOffice()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of the Bosses Office
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void BossesOffice::specialAction(Player &p)
{
    char input;
    
    //If boss already has the TPS report, he's distracted
    if (bossHasTPS == true)
    {
        std::cout << "You're in luck. The boss is still reviewing your TPS Report. ";
        std::cout << "Hurry and leave before he notices you!" << std::endl;
    }
    
    //If boss doesn't have the TPS report
    else
    {
        std::cout << "Your boss starts to question you. What are you doing? ";
        std::cout << "Why are you not at your desk? What are you up to? ";
        
        //If you have the TPS report
        if (p.doYouHaveTPS())
        {
            
            std::cout << "You remember you brought your TPS Report. ";
            std::cout << "Would you like to give the boss the TPS Report? (y/n)" << std::endl;
            std::cin >> input;
            do
            {
                if (input != 'y' && input != 'n')
                    std::cout << "Invalid input. Please try again." << std::endl;
                else
                {
                    //Give the boss the TPS report
                    if (input == 'y')
                    {
                        std::cout << "Your boss takes the TPS report and starts reviewing it. ";
                        std::cout << "Now's your chance to leave without him noticing, ";
                        std::cout << "but you have to hurry." << std::endl;
                        bossHasTPS = true;
                        p.sethasTPS(false);
                        p.removeFromPocket("TPS Report");
                    }
                    //You don't give the boss the TPS report
                    else
                    {
                        std::cout << "If only you had given your boss the TPS report. ";
                        std::cout << "Your boss continues to question your work ethic and life choices. ";
                        std::cout << "He demands you get back to your office and get back to work ";
                        std::cout << "immediately. You lose 5 minutes. You leave his office to continue ";
                        std::cout << "your journey." << std::endl;
                        //Remove 5 moves from counter
                        p.makeMove(5);
                    }
                }
            } while (input != 'n' && input != 'y');
        }
        
        //You do not have the TPS report, lose 5 turns
        else
        {
            std::cout << "If only you had brought that TPS report. ";
            std::cout << "Your boss continues to question your work ethic and life choices. ";
            std::cout << "He demands you get back to your office and get back to work ";
            std::cout << "immediately. You lose 5 minutes. You leave his office to continue ";
            std::cout << "your journey." << std::endl;
            //Remove 5 moves from counter
            p.makeMove(5);
        }
    }
}