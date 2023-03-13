# include "Ability.hpp"

Ability::Ability(string name) {
    this->name = name;
}

Ability::~Ability() {}

string Ability::getAbilityName() const {
    return this->name;
}