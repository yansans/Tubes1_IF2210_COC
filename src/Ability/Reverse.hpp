#ifndef REVERSE_HPP
#define REVERSE_HPP

#include "Ability.hpp"

class Reverse : public Ability
{
public:
    Reverse();
    ~Reverse();

    void executeAbility(Player *, long long &pts, vector<Player *>, DeckCards &, Turn &, map<Player *, Ability *>);
};

#endif