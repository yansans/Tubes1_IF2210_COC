# ifndef QUARTER_HPP
# define QUARTER_HPP

# include "Ability.hpp"

class Quarter : public Ability {
    public:
        Quarter(std::string name);
        ~Quarter();

        void executeAbility(const Player&);
};

# endif