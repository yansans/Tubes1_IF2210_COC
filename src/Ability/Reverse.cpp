# include "Reverse.hpp"

Reverse::Reverse() : Ability("REVERSE") {}

Reverse::~Reverse() {}

void Reverse::executeAbility(Player* player, long long& pts, vector<Player*> players, DeckCards& deck, Turn& turn, map<Player*, Ability*> playerAbility) {
    if(playerAbility[player]->getIsDisabled()) {
        cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
        throw StillCurrentTurn();
    }

    cout << player->getName() << " melakukan reverse!" << endl;
    turn.reverse();
    cout << "(sisa) urutan eksekusi giliran ini : ";

    vector<Player*> playersInTurn = turn.getPlayers();
    int curTurn = turn.getCurrentTurn();
    for(int i = curTurn+1; i < playersInTurn.size(); i++) {
        cout << playersInTurn[i]->getName() << ' '; 
    }
    cout << endl;
    cout << "urutan eksekusi giliran selanjutnya :";
    for(int i = 1; i < playersInTurn.size(); i++) {
        cout <<playersInTurn[i]->getName() << ' ';
    }
    cout << playersInTurn[0]->getName() << endl;
    cout << "Kamu masih dapat melakukan perintah!" << endl << endl;
    throw StillCurrentTurn();
}