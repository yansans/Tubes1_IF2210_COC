# ifndef QUADRUPLE_HPP
# define QUADRUPLE_HPP

# include "Ability.hpp"

class Quadruple : public Ability {
    public:
        Quadruple();
        ~Quadruple();

        void executeAbility(Player*, long long& pts, vector<Player*>, DeckCards&, Turn&, map<Player*, Ability*>);
};

# endif