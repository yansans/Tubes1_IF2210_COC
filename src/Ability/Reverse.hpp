# ifndef REVERSE_HPP
# define REVERSE_HPP

# include "Ability.hpp"

class Reverse : public Ability {
    public:
        Reverse(std::string name);
        ~Reverse();

        void executeAbility(const Player&);
};

# endif