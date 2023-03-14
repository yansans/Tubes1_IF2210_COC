# include "Switch.hpp"

Switch::Switch() : Ability("SWITCH") {}

Switch::~Switch() {}

void Switch::executeAbility(Player* player, vector<Player*> players, map<Player*, Ability*> playerAbility) {
    if(playerAbility[player]->getIsDisabled()){
        cout << "Oops, kartu ability switchmu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
    }else{
        cout << player->getName() << " melakukan switch!" << endl;

        vector<Player*> targetPlayers;
        for(Player* target : players){
            if(target != player) {
                targetPlayers.push_back(target);
            }
        }
        Player* choosedPlayer = Ability::choosePlayer(targetPlayers, "SWITCH", player);

        PlayerCards tmp = player->getCards();
        player->setCards(choosedPlayer->getCards());
        choosedPlayer->setCards(tmp);
        
        player->getCards().displayCard();
    }
}