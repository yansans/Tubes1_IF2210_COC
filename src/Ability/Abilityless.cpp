# include "Abilityless.hpp"

Abilityless::Abilityless() : Ability("ABILITYLESS") {}

Abilityless::~Abilityless() {}


void Abilityless::executeAbility(Player* player, vector<Player*> players, map<Player*, Ability*> playerAbility) {
    bool allAbilityUsed = true;

    for(auto it = playerAbility.begin(); it != playerAbility.end(); it++) {
        if(!it->second->getIsUsed() || !it->second->getIsDisabled()) {
            allAbilityUsed = false;
        }
    }

    if(allAbilityUsed) {
        playerAbility[player]->setIsDisabled(true);
        playerAbility[player]->setIsUsed(true);
        cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia";
    }
    else {
        cout << player->getName() << " akan mematikan kartu ability lawan!" << endl;

        vector<Player*> targetPlayers;
        for(Player* target : players){
            if(target != player) {
                targetPlayers.push_back(target);
            }
        }
        Player* choosedPlayer = Ability::choosePlayer(targetPlayers, "ABILITYLESS", player);

        if(playerAbility[choosedPlayer]->getIsUsed()) {
            cout << "Kartu ability " << choosedPlayer->getName() << " telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia";
        }
        else if(playerAbility[choosedPlayer]->getIsDisabled()) {
            cout << "Kartu ability " << choosedPlayer->getName() << " telah kamu matikan sebelumnya. Yah, sayang penggunaan kartu ini sia-sia";
        }
        else {   
            playerAbility[choosedPlayer]->setIsDisabled(true);
            playerAbility[player]->setIsUsed(true);
            cout << "Kartu ability pemain " << choosedPlayer->getName() << " telah dimatikan.";
        }
    }
}