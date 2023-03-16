#ifndef ABILITY_HOLDER
#define ABILITY_HOLDER

#include <map>

#include "../Ability/Ability.hpp"
#include "../Ability/Abilityless.hpp"
#include "../Ability/Quadruple.hpp"
#include "../Ability/Quarter.hpp"
#include "../Ability/ReRoll.hpp"
#include "../Ability/Reverse.hpp"
#include "../Ability/Swap.hpp"
#include "../Ability/Switch.hpp"
#include "../Exception/Exception.h"

class AbilityHolder
{
private:
    map<Player *, Ability *> playerAbility;

public:
    AbilityHolder();
    AbilityHolder(vector<Player *> &);
    ~AbilityHolder();

    void addAbility(Player *, Ability *);
    void removeAbility(Player *); // Remove the ability from a player

    bool playerHasAbility(Player *, Ability *); // Check if the player has the given ability

    Ability *checkPlayerAbility(Player *);
    Player *checkAbilityOwner(Ability *); // Who the given ability belongs to

    bool abilityCommandIsTrue(string abilityCommand);

    void executeAbility(string abilityString, Player *, long long &pts, vector<Player *>, DeckCards &, Turn &);
};

#endif