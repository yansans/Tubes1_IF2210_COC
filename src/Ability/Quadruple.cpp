# include "Quadruple.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE") {}

Quadruple::~Quadruple() {}

void Quadruple::executeAbility(Player* player, long long& pts) {
    cout << player->getName() << " melakukan QUADRUPLE! Poin hadiah naik dari "
         << pts << " menjadi " << (pts * 4) << "!" << std::endl;
    pts *= 4;
}