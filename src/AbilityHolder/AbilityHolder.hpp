# ifndef ABILITY_HOLDER
# define ABILITY_HOLDER

# include <map>

# include "../Ability/Ability.hpp"
# include "../Exception/Exception.h"

class AbilityHolder {
    private:
        map<Player*, Ability*> playerAbility;
    public:
        AbilityHolder(vector<Player*>);
        ~AbilityHolder();

        void addAbility(Player*, Ability*);
        void removeAbility(Player*); // Remove the ability from a player

        bool playerHasAbility(Player*, Ability*); // Check if the player has the given ability

        Ability* checkPlayerAbility(Player*);
        Player* checkAbilityOwner(Ability*); // Who the given ability belongs to
};

# endif