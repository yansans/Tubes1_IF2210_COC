#ifndef TURN_HPP
#define TURN_HPP

#include <vector>
#include <algorithm>
#include "../Player/Player.hpp"
using namespace std;

class Turn
{
private:
    int round;
    int firstTurn;
    int curTurn;
    Player *curPlayer;
    vector<Player *> players;
    void nextRound();

public:
    Turn(vector<Player *> players);
    Player *currentTurn();
    Player *nextTurn();
    vector<Player*> getPlayers();
    int getCurrentTurn();
    void reverse();
    int getRound() const;
};

#endif