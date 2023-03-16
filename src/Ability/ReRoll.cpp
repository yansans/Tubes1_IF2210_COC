#include "ReRoll.hpp"

ReRoll::ReRoll() : Ability("RE-ROLL") {}

ReRoll::~ReRoll() {}

void ReRoll::executeAbility(Player *player, long long &pts, vector<Player *> players, DeckCards &deck, Turn &turn, map<Player *, Ability *> playerAbility)
{
    if (playerAbility[player]->getIsDisabled())
    {
        cout << "Oops, kartu ability re-rollmu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
        throw StillCurrentTurn();
    }
    else
    {
        cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
        player->reset();
        player->takeCards();
        cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

        cout << "1. " << player->getCards().getLeftCard() << endl;

        cout << "2. " << player->getCards().getRightCard() << endl;
    }
}