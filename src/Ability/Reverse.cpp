# include "Reverse.hpp"

Reverse::Reverse() : Ability("REVERSE") {}

Reverse::~Reverse() {}

void Reverse::executeAbility(Player* player, Turn& turn) {
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