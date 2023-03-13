# ifndef REROLL_HPP
# define REROLL_HPP

# include "Ability.hpp"

class ReRoll : public Ability {
    public:
        ReRoll();
        ~ReRoll();

        void executeAbility();
};

# endif