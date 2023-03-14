# include "Quadruple.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE") {}

Quadruple::~Quadruple() {}

void Quadruple::executeAbility(Player* player, long long& pts, vector<Player*> players, DeckCards& deck, Turn& turn, map<Player*, Ability*> playerAbility) {
    if(playerAbility[player]->getIsDisabled()) {
        cout << "Oops, kartu ability quadruplemu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
        throw StillCurrentTurn();
    }
    else {
        cout << player->getName() << " melakukan QUADRUPLE! Poin hadiah naik dari "
             << pts << " menjadi " << (pts * 4) << "!" << std::endl;
        pts *= 4;
    }
}