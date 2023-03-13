# ifndef SWITCH_HPP
# define SWITCH_HPP

# include "Ability.hpp"

class Switch : public Ability {
    public:
        Switch();
        ~Switch();

        void executeAbility();
};

# endif