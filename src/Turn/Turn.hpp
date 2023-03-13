#ifndef TURN_HPP
#define TURN_HPP

#include <bits/stdc++.h>
#include "../Player/Player.hpp"
using namespace std;

class Turn
{
private:
    int round;
    int first;
    int cur;
    vector<Player> players;
    void nextRound();

public:
    Turn(vector<Player> players);
    Player nextTurn();
    void reverse();
    int getRound() const;  
};

#endif