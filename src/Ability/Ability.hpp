# ifndef ABILITY_HPP
# define ABILITY_HPP

# include "../Player/Player.hpp"
# include "../Values/Card.hpp"
# include "../InventoryHolder/DeckCards.hpp"
# include "../AbilityHolder/AbilityHolder.hpp"

# include <iostream>
# include <string>
using namespace std;

class Ability {
    protected:
        string name;

    public:
        Ability(string name);
        ~Ability();

        string getAbilityName() const;
};

# endif