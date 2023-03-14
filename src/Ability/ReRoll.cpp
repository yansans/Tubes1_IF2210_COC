# include "ReRoll.hpp"

ReRoll::ReRoll() : Ability("RE-ROLL") {}

ReRoll::~ReRoll() {}

void ReRoll::executeAbility(Player* player, long long& pts, vector<Player*> players, DeckCards& deck, Turn& turn, map<Player*, Ability*> playerAbility) {
    if(playerAbility[player]->getIsDisabled()) {
        cout << "Oops, kartu ability re-rollmu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
    }
    else{
        cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
        player->takeCards(deck);
        cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

        cout << "1. " << player->getCards().getLeftCard().get_number()
             << ' ' << player->getCards().getLeftCard().get_colour() << endl;

        cout << "2. " << player->getCards().getRightCard().get_number()
             << ' ' << player->getCards().getRightCard().get_colour() << endl;
    }
}