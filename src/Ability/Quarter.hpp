#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

class Quarter : public Ability
{
public:
    Quarter();
    ~Quarter();

    void executeAbility(Player *, long long &pts, vector<Player *>, DeckCards &, Turn &, map<Player *, Ability *>);
};

#endif