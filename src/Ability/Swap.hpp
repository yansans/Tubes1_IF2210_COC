# ifndef SWAP_HPP
# define SWAP_HPP

# include "Ability.hpp"

class Swap : public Ability {
    public:
        Swap(std::string name);
        ~Swap();

        void executeAbility(const Player&);
};

# endif