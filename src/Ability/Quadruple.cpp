# include "Quadruple.hpp"

Quadruple::Quadruple(std::string name) : Ability(name) {}

Quadruple::~Quadruple() {}

void Quadruple::executeAbility(const Player& P) {
    this->isActive = true;
    // Executes Quadruple
}