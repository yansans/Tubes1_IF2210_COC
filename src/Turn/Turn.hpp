#ifndef TURN_HPP
#define TURN_HPP

#include <bits/stdc++.h>
#include "../Player/Player.hpp"
using namespace std;

class Turn
{
private:
    int round;
    int firstTurn;
    int curTurn;
    vector<Player> players;
    void nextRound();

public:
    Turn(vector<Player> players);
    Player currentTurn();
    Player nextTurn();
    void reverse();
    int getRound() const;
};

#endif