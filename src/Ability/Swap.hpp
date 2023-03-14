# ifndef SWAP_HPP
# define SWAP_HPP

# include "Ability.hpp"
# include <map>
# include "../Exception/Exception.h"

class Swap : public Ability {
    private:
        int chooseHand(Player& player);
    public:
        Swap();
        ~Swap();

        void executeAbility(Player*, vector<Player*>, map<Player*, Ability*>);
};

# endif