# include "Abilityless.hpp"

Abilityless::Abilityless(std::string name) : Ability(name) {}

Abilityless::~Abilityless() {}

void Abilityless::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes Abilityless
}