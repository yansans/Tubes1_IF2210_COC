# include "Quarter.hpp"

Quarter::Quarter() : Ability("QUARTER") {}

Quarter::~Quarter() {}

void Quarter::executeAbility(Player* player, long long& pts) {
    cout << player->getName() << " melakukan QUARTER! ";
    if(pts < 4LL) {                                             // Asumsi poin harus bernilai minimal 4 agar ability berefek
        cout << "Sayangnya poin hadiah sudah bernilai\n "
             <<  pts << ". Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
    else {
        cout << "Poin hadiah turun dari " << pts << " menjadi " << (pts / 4) << '!'
             << endl;
        pts /= 4;
    }
}