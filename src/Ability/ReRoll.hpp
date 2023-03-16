#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

class ReRoll : public Ability
{
public:
    ReRoll();
    ~ReRoll();

    void executeAbility(Player *, long long &pts, vector<Player *>, DeckCards &, Turn &, map<Player *, Ability *>);
};

#endif