# ifndef QUARTER_HPP
# define QUARTER_HPP

# include "Ability.hpp"

class Quarter : public Ability {
    public:
        Quarter();
        ~Quarter();

        void executeAbility();
};

# endif