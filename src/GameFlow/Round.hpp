#ifndef ROUND_HPP
#define ROUND_HPP

#include "Game.hpp"
using namespace std;

class Round : public Game
{
private:
    int roundCount;

public:
    Round();
    int getRound() const;
    void nextRound(vector<Player *> &players);
};

#endif