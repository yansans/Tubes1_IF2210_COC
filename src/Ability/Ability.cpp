# include "Ability.hpp"

Ability::Ability(string name) {
    this->name = name;
    this->isUsed = false;
    this->isDisabled = false;
}

Ability::~Ability() {}

string Ability::getAbilityName() const {
    return this->name;
}

void Ability::setIsUsed(bool isUsed) {
    this->isUsed = isUsed;
}

bool Ability::getIsUsed() {
    return this->isUsed;
}

void Ability::setIsDisabled(bool isDisabled) {
    this->isDisabled = isDisabled;
}

bool Ability::getIsDisabled() {
    return this->isDisabled;
}

void Ability::executeAbility(Player& player, vector<Player*> players) {}