# include "ReRoll.hpp"

ReRoll::ReRoll(std::string name) : Ability(name) {}

ReRoll::~ReRoll() {}

void ReRoll::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes ReRoll
}