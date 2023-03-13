# include "Ability.hpp"

Ability::Ability(std::string name) {
    this->name = name;
    this->isActive = false;
}

Ability::~Ability() {}

std::string Ability::getAbilityOwner() {
    return this->name;
}

void Ability::setAbilityOwner(std::string name) {
    this->name = name;
}

bool Ability::getIsActive() {
    return this->isActive;
}

void Ability::setIsActive(bool isActive) {
    this->isActive = isActive;
}