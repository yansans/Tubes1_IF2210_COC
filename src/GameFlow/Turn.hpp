#ifndef TURN_HPP
#define TURN_HPP

#include <vector>
#include <algorithm>
#include "Round.hpp"
using namespace std;

class Turn : public Round
{
private:
    int firstTurn;
    int curTurn;
    Player *curPlayer;
    vector<Player *> players;

public:
    Turn();
    Turn(vector<Player *> players);
    Player *currentTurn();
    void nextTurn();
    void reverse();
    vector<Player *> getPlayers();
    int getCurrentTurn();
};

#endif