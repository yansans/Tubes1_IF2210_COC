# ifndef QUADRUPLE_HPP
# define QUADRUPLE_HPP

# include "Ability.hpp"

class Quadruple : public Ability {
    public:
        Quadruple(std::string name);
        ~Quadruple();

        void executeAbility(const Player&);
};

# endif;