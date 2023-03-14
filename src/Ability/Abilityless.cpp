# include "Abilityless.hpp"

Abilityless::Abilityless() : Ability("ABILITYLESS") {}

Abilityless::~Abilityless() {}

void Abilityless::executeAbility(Player& player, vector<Player*> players, map<Player*, Ability*> playerAbility) {
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
    cout << "Kartu ability pemain " << temp[number] << " telah dimatikan.";
}