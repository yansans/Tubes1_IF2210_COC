# ifndef REROLL_HPP
# define REROLL_HPP

# include "Ability.hpp"

class ReRoll : public Ability {
    public:
        ReRoll(std::string name);
        ~ReRoll();

        void executeAbility(const Player&);
};

# endif