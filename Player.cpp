/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Player definitions
 * ******************************************************/
#include "Player.h"
#include <iostream>

/*********************************************************************  
** Function: Constructor
** Description: Start off all applicable values as blank or false. Set # of moves
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
Player::Player()
{
    myPocket[0] = "";
    myPocket[1] = "";
    setHasKey(false);
    setHasTP(false);
    sethasTPS(false);
    setMissionComplete(false);
    setMoves(20);
}

/*********************************************************************  
** Function: setHasKey
** Description: Simple function to set the hasKey bool
** Parameters: Pass in bool to set
** Pre-Conditions: hasKey bool value
** Post-Conditions: hasKey bool has new value
*********************************************************************/
void Player::setHasKey(bool h){hasKey = h;}

/*********************************************************************  
** Function: doYouHaveKey
** Description: Simple function to return the hasKey value
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
bool Player::doYouHaveKey(){return hasKey;}

/*********************************************************************  
** Function: getKey
** Description: Function to ask the user if they want to pick up the key,
** and if so, add the key to the array.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: Might change "hasKey" depending on user selection, as well
** as the myPocket array.
*********************************************************************/
void Player::getKey()
{
    char input, input2;
    int available;
    
    std::cout << "Would you like to put the key in your pocket? (y/n)" << std::endl;
    do
    {
        std::cin >> input;
        if (input != 'y' && input != 'n')
            std::cout << "Invalid input. Please try again." << std::endl;
        else if (input == 'y')
        {
            //Check for available spot in array (pocket)
            if (myPocket[0] == "")
                //Spot 1 is open
                available = 0;
            else if (myPocket[1] == "")
                //Spot 2 is open
                available = 1;
            else
                //No spots open
                available = 2;
            
            //No spots available
            if (available == 2)
            {
                std::cout << "You have no room in your pockets. Would you like to remove ";
                std::cout << "something from your pockets? (y/n)" << std::endl;
                do
                {
                    std::cin >> input2;
                    if (input2 != 'y' && input2 != 'n')
                        std::cout << "Invalid input. Please try again." << std::endl;
                    else 
                    {
                        if (input2 == 'y')
                        {
                            //Call function to pick what item to replace
                            int p = removeItem();
                            removeFromPocket(myPocket[p]);
                            myPocket[p] = "Key";
                            setHasKey(true);
                        }
                    }
                } while (input2 != 'y' && input2 != 'n');
            }
            else
            {
                //Add item if you have room
                myPocket[available] = "Key";
                setHasKey(true);
            }
        }
    } while (input != 'y' && input != 'n');
}

/*********************************************************************  
** Function: setHasTP
** Description: Simple function to set the hasTP bool
** Parameters: Pass in bool to set
** Pre-Conditions: hasTP bool value
** Post-Conditions: hasTP bool has new value
*********************************************************************/
void Player::setHasTP(bool t){hasTP = t;}

/*********************************************************************  
** Function: doYouHaveTP
** Description: Simple function to return the hasTP value
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
bool Player::doYouHaveTP(){return hasTP;}

/*********************************************************************  
** Function: getTP
** Description: Function to ask the user if they want to pick up the TP,
** and if so, add the TP to the array.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: Might change "hasTP" depending on user selection, as well
** as the myPocket array.
*********************************************************************/
void Player::getTP()
{
    char input, input2;
    int available;
    
    std::cout << "Would you like to put the Toilet Paper in your pocket? (y/n)" << std::endl;
    do
    {
        std::cin >> input;
        if (input != 'y' && input != 'n')
            std::cout << "Invalid input. Try again." << std::endl;
        else if (input == 'y')
        {
            //Check for available spot in array (pocket)
            if (myPocket[0] == "")
                //Spot 1 is open
                available = 0;
            else if (myPocket[1] == "")
                //Spot 2 is open
                available = 1;
            else
                //No spots open
                available = 2;
            
            //No spots avilable
            if (available == 2)
            {
                std::cout << "You do not have room in your pockets. Would you like to remove ";
                std::cout << "something from your pockets? (y/n)" << std::endl;
                do
                {
                    std::cin >> input2;
                    if (input2 != 'y' && input2 != 'n')
                        std::cout << "Invalid input. Please try again." << std::endl;
                    else
                    {
                        if (input2 == 'y')
                        {
                            //Choose which item to replace
                            int p = removeItem();
                            removeFromPocket(myPocket[p]);
                            myPocket[p] = "Toilet Paper";
                            setHasTP(true);
                        }
                    }   
                } while (input2 != 'y' && input2 != 'n');
            }
            else
            {                
                //Add item if room is available
                myPocket[available] = "Toilet Paper";
                setHasTP(true);
            }
        }
    } while (input != 'y' && input != 'n');
}

/*********************************************************************  
** Function: setHasTPS
** Description: Simple function to set the hasTPS bool
** Parameters: Pass in bool to set
** Pre-Conditions: hasTPS bool value
** Post-Conditions: hasTPS bool has new value
*********************************************************************/
void Player::sethasTPS(bool t){hasTPS = t;}

/*********************************************************************  
** Function: doYouHaveTPS
** Description: Simple function to return the hasTPS value
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
bool Player::doYouHaveTPS(){return hasTPS;}

/*********************************************************************  
** Function: getTPS
** Description: Function to ask the user if they want to pick up the TPS Report,
** and if so, add the TPS Report to the array.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: Might change "hasTPS" depending on user selection, as well
** as the myPocket array.
*********************************************************************/
bool Player::getTPS()
{
    char input, input2;
    int available;
    
    std::cout << "Would you like to put the TPS Report in your pocket? (y/n)" << std::endl;
    do
    {
        std::cin >> input;
        if (input != 'y' && input != 'n')
            std::cout << "Invalid input. Please try again." << std::endl;
        else if (input == 'y')
        {
            //Check for available spot in array (pocket)
            if (myPocket[0] == "")
                //Spot 1 is open
                available = 0;
            else if (myPocket[1] == "")
                //Spot 2 is open
                available = 1;
            else
                //No spots open
                available = 2;
            
            //No spots available
            if (available == 2)
            {
                std::cout << "You have no room in your pockets. Would you like to remove ";
                std::cout << "something from your pockets? (y/n)" << std::endl;
                do
                {
                    std::cin >> input2;
                    if (input2 != 'y' && input2 != 'n')
                        std::cout << "Invalid input. Please try again." << std::endl;
                    else 
                    {
                        if (input2 == 'y')
                        {
                            //Choose what item to replace
                            int p = removeItem();
                            removeFromPocket(myPocket[p]);
                            myPocket[p] = "TPS Report";
                            sethasTPS(true);
                            return true;
                        }
                        else
                            return false;
                    }
                } while (input2 != 'y' && input2 != 'n');
            }
            else
            {
                //Add item to pocket if room is available
                myPocket[available] = "TPS Report";
                sethasTPS(true);
                return true;
            }
        }
        else if (input == 'n')
            return false;
    } while (input != 'y' && input != 'n');
}

/*********************************************************************  
** Function: setHasDonut
** Description: Simple function to set the hasDonut bool
** Parameters: Pass in bool to set
** Pre-Conditions: hasDonut bool value
** Post-Conditions: hasDonut bool has new value
*********************************************************************/
void Player::setHasDonut(bool d){hasDonut = d;}

/*********************************************************************  
** Function: doYouHaveDonut
** Description: Simple function to return the hasDonut value
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
bool Player::doYouHaveDonut(){return hasDonut;}

/*********************************************************************  
** Function: getDonut
** Description: Function to ask the user if they want to pick up the donut,
** and if so, add the donut to the array.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: Might change "hasDonut" depending on user selection, as well
** as the myPocket array.
*********************************************************************/
bool Player::getDonut()
{
    char input, input2;
    int available;
    
    std::cout << "Would you like to put the Donut in your pocket? (y/n)" << std::endl;
    do
    {
        std::cin >> input;
        if (input != 'y' && input != 'n')
            std::cout << "Invalid input. Please try again." << std::endl;
        else if (input == 'y')
        {
            //Check for available spot in array (pocket)
            if (myPocket[0] == "")
                //Spot 1 is open
                available = 0;
            else if (myPocket[1] == "")
                //Spot 2 is open
                available = 1;
            else
                //No spots open
                available = 2;
            
            //If no room is available
            if (available == 2)
            {
                std::cout << "You have no room in your pockets. Would you like to remove ";
                std::cout << "something from your pockets? (y/n)" << std::endl;
                do
                {
                    std::cin >> input2;
                    if (input2 != 'y' && input2 != 'n')
                        std::cout << "Invalid input. Please try again." << std::endl;
                    else 
                    {
                        if (input2 == 'y')
                        {
                            //Choose which item to replace
                            int p = removeItem();
                            removeFromPocket(myPocket[p]);
                            myPocket[p] = "Donut";
                            setHasDonut(true);
                            return true;
                        }
                        else
                            return false;
                    }
                } while (input2 != 'y' && input2 != 'n');
            }
            else
            {
                //Add item if there is room available
                myPocket[available] = "Donut";
                setHasDonut(true);
                return true;
            }
        }
        else if (input == 'n')
            return false;
    } while (input != 'y' && input != 'n');
}

/*********************************************************************  
** Function: removeFromPocket
** Description: Function to remove the requested item from the array as well
** as change the "has..." bool value.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: Changes the array string and the "has..." variable
*********************************************************************/
void Player::removeFromPocket(std::string s)
{
    //Remove from pocket array
    if (myPocket[0] == s)
        myPocket[0] = "";
    else if (myPocket[1] == s)
        myPocket[1] = "";
    //Reset appropriate 'has' variable to false
    if (s == "Key") 
        setHasKey(false);
    else if (s == "TPS Report")
        sethasTPS(false);
    else if (s == "Toilet Paper")
        setHasTP(false);
    else if (s == "Donut")
        setHasDonut(false);
}

/*********************************************************************  
** Function: removeItem
** Description: Function to display the items in myPocket to the user, and
** ask which one they'd like to replace.
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: returns the int for the user's selection
*********************************************************************/
int Player::removeItem()
{
    int input;
    std::cout << "Which item would you like to remove?" << std::endl;
    std::cout << "1. " << myPocket[0] << std::endl;
    std::cout << "2. " << myPocket[1] << std::endl;
    do
    {
        std::cin >> input;
        if (input == 1)
            return 0;
        else if (input == 2)
            return 1;
        else
            std::cout << "Invalid input. Please try again." << std::endl;
        
    } while (input != 1 && input != 2);
}

/*********************************************************************  
** Function: setMissionComplete
** Description: Simple function to set the mission complete bool
** Parameters: bool
** Pre-Conditions: N/A
** Post-Conditions: changes "objectiveComplete" bool to parameter
*********************************************************************/
void Player::setMissionComplete(bool m){objectiveComplete = m;}

/*********************************************************************  
** Function: missionComplete
** Description: Simple function to return the value of the objectiveComplete bool
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: return bool value
*********************************************************************/
bool Player::missionComplete(){return objectiveComplete;}

/*********************************************************************  
** Function: setMoves
** Description: Simple function to set the number of moves allowed
** Parameters: int
** Pre-Conditions: N/A
** Post-Conditions: changes "movesLeft" variable to the int parameter
*********************************************************************/
void Player::setMoves(int m){movesLeft = m;}

/*********************************************************************  
** Function: getMoves
** Description: Simple function to return the number of moves left
** Parameters: None
** Pre-Conditions: N/A
** Post-Conditions: return int value
*********************************************************************/
int Player::getMoves(){return movesLeft;}

/*********************************************************************  
** Function: makeMove
** Description: Subtract the defined number of moves. If moves reaches 0,
** let the player know they've done pooped themself.
** Parameters: int for number of moves to subtract
** Pre-Conditions: N/A
** Post-Conditions: changes "movesLeft" variable
*********************************************************************/
void Player::makeMove(int m)
{
    movesLeft = movesLeft - m;
    if (movesLeft == 0)
    {
        std::cout << "You ran out of time! You've done POOPED yourself! ";
        std::cout << "You will forever be shamed around the office. ";
        std::cout << "You'll probably need to change jobs, or even move cities ";
        std::cout << "to escape the embarrassment. Better luck next time!";
        std::cout << std::endl;
    }
}