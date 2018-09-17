/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Chatty Cathy definitions
 * ******************************************************/
#include "ChattyCathy.h"
#include <cstdlib>
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Assign pointers to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
ChattyCathy::ChattyCathy()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
    cathyHasDonut = false;
    roomName = "Chatty Cathy's Office. ";
}

/*********************************************************************  
** Function: Deconstructor
** Description: Assign pointers back to NULL
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
ChattyCathy::~ChattyCathy()
{
    left = NULL;
    right = NULL;
    straight = NULL;
    back = NULL;
}

/*********************************************************************  
** Function: specialAction
** Description: Determines the proper logic path for the options of Chatty Cathys Office
** Parameters: Passes in the player reference
** Pre-Conditions: Player's data members
** Post-Conditions: Players data memebers could be changed based on the chosen actions
*********************************************************************/
void ChattyCathy::specialAction(Player &p)
{
    char input;
    
    //If ChattyCathy already has the donut, she's distracted
    if (cathyHasDonut == true)
    {
        std::cout << "You're in luck. Chatty Cathy is still enjoying the donut you gave her. ";
        std::cout << "Hurry and leave before she notices you again!" << std::endl;
    }
    
    //If ChattyCathy doesn't have the donut
    else
    {
        std::cout << "Chatty Cathy quickly spots you in her office and starts doing ";
        std::cout << "what she does best... chat like there's no tomorrow. How's your family? How's your day? ";
        std::cout << "How's your TPS Report? Did I tell you about my new cat pickles? I just started to ";
        std::cout << "learn how to crochet. I was thinking of ordering sandwiches for lunch, what do you think? ";
        
        //You have the donut
        if (p.doYouHaveDonut())
        {
            std::cout << "You remember you picked up a donut from the breakroom. Maybe Chatty Cathy wants it. ";
            std::cout << "Would you like to give Chatty Cathy the donut? (y/n)" << std::endl;
            std::cin >> input;
            do
            {
                if (input != 'y' && input != 'n')
                    std::cout << "Invalid input. Please try again." << std::endl;
                
                //You give Chatty Cathy the donut
                else if (input == 'y')
                {
                    std::cout << "Chatty Cathy accepts the donut with a big Thank You. ";
                    std::cout << "Now's your chance to leave while she's eating, ";
                    std::cout << "but you have to hurry." << std::endl;
                    cathyHasDonut = true;
                    p.setHasDonut(false);
                    p.removeFromPocket("Donut");
                }
                
                //You don't give Chatty Cathy the donut
                else
                {
                    std::cout << "If only you had given the donut to Chatty Cathy. ";
                    std::cout << "Chatty Cathy continues on about her cats and new hobbies without taking a breath. ";
                    std::cout << "She lets you know she'll swing by your office later to get your lunch order. ";
                    std::cout << "You lose 5 minutes during the assult on your ears. You run out of her office ";
                    std::cout << "as she takes her first breath." << std::endl;
                    //Remove 5 moves from counter
                    p.makeMove(5);
                }
                
            } while (input != 'n' && input != 'y');
        }
        //You do not have the donut, lose 5 turns
        else
        {
            std::cout << "If only you had something to give Chatty Cathy. ";
            std::cout << "Chatty Cathy continues on about her cats and new hobbies without taking a breath. ";
            std::cout << "She lets you know she'll swing by your office later to get your lunch order. ";
            std::cout << "You lose 5 minutes during the assult on your ears. You run out of her office ";
            std::cout << "as she takes her first breath." << std::endl;
            //Remove 5 moves from counter
            p.makeMove(5);
        }
    }
}
