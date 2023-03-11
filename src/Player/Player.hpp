#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <bits/stdc++.h>
#include "PlayerCards.hpp"
using namespace std;

class Player
{
private:
    string name;
    long long point;
    PlayerCards cards;
    // Ability abilityCard;
    bool done;

public:
    Player(string name);
    string getName() const;
    void setName(string name);
    long long getPoint() const;
    void addPoint(long long point);
    bool isDone() const;
    void setDone();
    void takeCards();
    void takeAbilityCard();
    void useAbilityCard();
    void reset();
};

#endif