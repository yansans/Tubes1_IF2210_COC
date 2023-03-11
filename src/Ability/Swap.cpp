# include "Swap.hpp"

Swap::Swap(std::string name) : Ability(name) {}

Swap::~Swap() {}

void Swap::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes Swap
}