#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Ability.hpp"

class Abilityless : public Ability
{
public:
    Abilityless();
    ~Abilityless();

    void executeAbility(Player *, long long &pts, vector<Player *>, DeckCards &, Turn &, map<Player *, Ability *>);
};

#endif