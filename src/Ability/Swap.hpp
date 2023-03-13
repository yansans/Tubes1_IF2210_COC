# ifndef SWAP_HPP
# define SWAP_HPP

# include "Ability.hpp"

class Swap : public Ability {
    public:
        Swap();
        ~Swap();

        void executeAbility();
};

# endif