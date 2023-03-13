# ifndef ABILITYLESS_HPP
# define ABILITYLESS_HPP

# include "Ability.hpp"

class Abilityless : public Ability {
    public:
        Abilityless(std::string name);
        ~Abilityless();

        void executeAbility(const Player&);
};

# endif