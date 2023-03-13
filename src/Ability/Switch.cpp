# include "Switch.hpp"

Switch::Switch(std::string name) : Ability(name) {}

Switch::~Switch() {}

void Switch::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes Switch
}