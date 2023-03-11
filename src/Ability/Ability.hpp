# ifndef ABILITY_HPP
# define ABILITY_HPP

# include "../Player/Player.hpp"

# include <iostream>
# include <string>

class Ability {
    protected:
        std::string name;
        bool isActive;

    public:
        Ability(std::string name);
        ~Ability();

        std::string getAbilityOwner();
        void setAbilityOwner(std::string name);

        bool getIsActive();
        void setIsActive(bool isActive);

        virtual void executeAbility(const Player&) = 0;
};

# endif