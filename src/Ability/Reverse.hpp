# ifndef REVERSE_HPP
# define REVERSE_HPP

# include "Ability.hpp"

class Reverse : public Ability {
    public:
        Reverse();
        ~Reverse();

        void executeAbility(Player*, Turn&);
};

# endif