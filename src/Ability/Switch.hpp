#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "Ability.hpp"
#include <map>

class Switch : public Ability
{
public:
    Switch();
    ~Switch();

    void executeAbility(Player *, long long &pts, vector<Player *>, DeckCards &, Turn &, map<Player *, Ability *>);
};

#endif