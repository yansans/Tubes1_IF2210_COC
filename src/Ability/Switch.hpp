# ifndef SWITCH_HPP
# define SWITCH_HPP

# include "Ability.hpp"

class Switch : public Ability {
    public:
        Switch(std::string name);
        ~Switch();

        void executeAbility(const Player&);
};

# endif