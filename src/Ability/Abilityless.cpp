# include "Abilityless.hpp"

Abilityless::Abilityless() : Ability("ABILITYLESS") {}

Abilityless::~Abilityless() {}

void Abilityless::executeAbility(Player& player, vector<Player*> players, map<Player*, Ability*> playerAbility) {
    bool allAbilityUsed = true;

    for(auto it = playerAbility.begin(); it != playerAbility.end(); it++) {
        if(!it->second->getIsUsed() || !it->second->getIsDisabled()) {
            allAbilityUsed = false;
        }
    }

    if(allAbilityUsed) {
        playerAbility[&player]->setIsDisabled(true);
        playerAbility[&player]->setIsUsed(true);
        cout << "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia";
    }
    cout << player.getName() << " akan mematikan kartu ability lawan!" << endl;
    cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;

    map<int, Player*> temp;
    int number = 0;
    for(int i = 0; i < players.size(); i++) {
        if(players[i]->getName() != player.getName()) {
            number++;
            cout << number << ". " << players[i]->getName();
            temp[number] = players[i];
        }
    }
    cin >> number;
    
    playerAbility[temp[number]]->setIsDisabled(true);
    playerAbility[&player]->setIsUsed(true);
    cout << "Kartu ability pemain " << temp[number] << " telah dimatikan.";
}