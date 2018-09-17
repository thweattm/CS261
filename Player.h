/*********************************************************
 * Author: Mike Thweatt
 * Date: 08/02/16
 * Description: Player Headers
 * ******************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
public:
    Player();
    //Key Functions
    void setHasKey(bool);
    bool doYouHaveKey();
    void getKey();
    //TP Functions
    void setHasTP(bool);
    bool doYouHaveTP();
    void getTP();
    //TPS Functions
    bool getTPS();
    void sethasTPS(bool);
    bool doYouHaveTPS();
    //Donut Functions
    bool getDonut();
    void setHasDonut(bool);
    bool doYouHaveDonut();
    //Misc Functions
    void setMissionComplete(bool);
    bool missionComplete();
    int removeItem();
    void setMoves(int);
    void makeMove(int);
    int getMoves();
    void removeFromPocket(std::string);
    
private:
    bool hasKey;
    bool hasTP;
    bool hasTPS;
    bool hasDonut;
    std::string myPocket[2]; //Array to hold 2 items
    bool objectiveComplete;
    int movesLeft;
};

#endif // Player_H
