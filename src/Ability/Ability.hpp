# ifndef ABILITY_HPP
# define ABILITY_HPP

# include "../Player/Player.hpp"
# include "../Values/Card.hpp"
# include "../InventoryHolder/DeckCards.hpp"
# include "../Turn/Turn.hpp"

# include <iostream>
# include <string>
# include <map>
using namespace std;

class Ability {
    protected:
        string name;
        bool isUsed;
        bool isDisabled;

    public:
        Ability(string name);
        ~Ability();

        string getAbilityName() const;

        void setIsUsed(bool);
        bool getIsUsed();

        void setIsDisabled(bool);
        bool getIsDisabled();

        static Player* choosePlayer(vector<Player*>, string, Player*);

        virtual void executeAbility(Player&, vector<Player*>) = 0;
};

# endif