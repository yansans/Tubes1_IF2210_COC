# ifndef SWITCH_HPP
# define SWITCH_HPP

# include "Ability.hpp"
# include <map>

class Switch : public Ability {
    public:
        Switch();
        ~Switch();

        void executeAbility(Player*, vector<Player*>, map<Player*, Ability*>);
};

# endif