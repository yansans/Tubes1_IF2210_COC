# include "Quarter.hpp"

Quarter::Quarter(std::string name) : Ability(name) {}

Quarter::~Quarter() {}

void Quarter::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes Quarter
}