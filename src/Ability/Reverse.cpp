# include "Reverse.hpp"

Reverse::Reverse() : Ability("REVERSE") {}

Reverse::~Reverse() {}

void Reverse::executeAbility(Player* player, long long& pts, vector<Player*> players, DeckCards& deck, Turn& turn, map<Player*, Ability*> playerAbility) {
    if(playerAbility[player]->getIsDisabled()) {
        cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
    }

    cout << player->getName() << " melakukan reverse!" << endl;
    turn.reverse();
    cout << "(sisa) urutan eksekusi giliran ini : ";

    vector<Player*> players = turn.getPlayers();
    int curTurn = turn.getCurrentTurn();
    for(int i = curTurn; i < players.size(); i++) {
        cout << "<" << players[i]->getName() << "> "; 
    }
    cout << endl;
    for(int i = 0; i < players.size(); i++) {
        cout << "<" <<players[i]->getName() << "> ";
    }
    cout << endl;
}