/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Program to create a game of rooms which lets
 * the player navigate through rooms to complete the required
 * objective.
 * ******************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Room.h"
#include "YourOffice.h"
#include "HallWay.h"
#include "BreakRoom.h"
#include "Bathroom.h"
#include "Closet.h"
#include "AirDuct.h"
#include "Player.h"
#include "BossesOffice.h"
#include "ChattyCathy.h"

int showMenu()
{
    int input;
    std::cout << "\nPlease select a direction to move. ";
    std::cout << "Please enter only the number for the ";
    std::cout << "direction you'd like to move." << std::endl;
    std::cout << "1. Left" << std::endl;
    std::cout << "2. Right" << std::endl;
    std::cout << "3. Straight" << std::endl;
    std::cout << "4. Back" << std::endl;
    std::cout << "5. Reveal the objective" << std::endl;
    std::cout << "6. Quit Program" << std::endl;
    std::cin >> input;
    return input;
}

int main()
{
    //Seed for random number generators
    srand(time(NULL));
    
    //Create the rooms
    Room *null;
    null = NULL;
    
    Room *office;
    YourOffice o;
    office = &o;
    
    Room *hall;
    HallWay h;
    hall = &h;
    
    Room *hall2;
    HallWay h2;
    hall2 = &h2;

    Room *breakRoom;
    BreakRoom b;
    breakRoom = &b;
    
    Room *bathRoom;
    Bathroom br;
    bathRoom = &br;
    
    Room *closet;
    Closet c;
    closet = &c;
    
    Room *boss;
    BossesOffice bo;
    boss = &bo;
    
    Room *cathy;
    ChattyCathy cc;
    cathy = &cc;
    
    //Place holder for airducts
    Room *airDuct = NULL;
    
    //Set Pointers for each room to construct map (Left, Right, Straight, Back)
    office->setPointers(null, null, hall, null);
    hall->setPointers(closet, breakRoom, hall2, office);
    hall2->setPointers(cathy, boss, bathRoom, hall);
    closet->setPointers(null, null, null, hall);
    bathRoom->setPointers(null, null, null, hall2);
    breakRoom->setPointers(null, null, null, hall);
    boss->setPointers(null, null, null, hall2);
    cathy->setPointers(null, null, null, hall2);
    
    Room *currentRoom = office;
    Player Milton;
  
    //Intro
    std::cout << "It's 9am. You're in the office. You're two cups of ";
    std::cout << "coffee into your day, when suddenly... ";
    std::cout << "Nature calls you on speed dial. Hurry to the bathroom! ";
    std::cout << "Before you have an accident!\n\n" << std::endl;
    
    std::cout << "You are in " << currentRoom->getRoomname();
    currentRoom->specialAction(Milton);
    
    int input;
    do
    {
        //Show menu
        input = showMenu();
        
        //Valid move
        if (input > 0 && input < 5)
        {
            //Decrease moves counter
            Milton.makeMove(1);
            if (Milton.getMoves() >0)
            {
                //If the direction is not NULL
                if (currentRoom->moveDirection(currentRoom, input))
                {    
                    std::cout << "\nYou are in ";
                    std::cout << currentRoom->getRoomname();
                    currentRoom->specialAction(Milton);
                }
                //NULL pointers create a new 'air duct' room with random exits
                else
                {
                    //Delete air duct object if it was created in the previous loop
                    if (airDuct !=NULL)
                    {
                        delete airDuct;
                        airDuct = NULL;
                    }
                    airDuct = new AirDuct;
                    //Pick 1 of 4 random exit setups
                    int i = std::rand() % 4 + 1;
                    switch (i)
                    {
                        case 1: airDuct->setPointers(office, hall, breakRoom, closet);
                                break;
                        case 2: airDuct->setPointers(hall, closet, hall, breakRoom);
                                break;
                        case 3: airDuct->setPointers(hall, hall, office, closet);
                                break;
                        case 4: airDuct->setPointers(breakRoom, closet, hall, office);
                    };
                    currentRoom = airDuct;
                    std::cout << "\nYou are in ";
                    std::cout << currentRoom->getRoomname();
                    currentRoom->specialAction(Milton);
                }
            }
        }
        
        //Reveal Objective
        else if (input == 5)
        {
            std::cout << "\nFind the Janitor in the hallway, ";
            std::cout << "get the key from him, unlock cabinet in closet, ";
            std::cout << "get toilet paper, get to bathroom.\n" << std::endl;
        }
        
        //Invalid selection
        else if (input > 6 || input < 1)
            std::cout << "Invalid entry." << std::endl;
        
    } while (input != 6 && Milton.missionComplete() == false && Milton.getMoves() != 0);
    
    //Make sure to delete any leftover airduct that was created
    delete airDuct;
    airDuct = NULL;
                        
	return 0;
}
