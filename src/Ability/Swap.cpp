#include "Swap.hpp"

Swap::Swap() : Ability("SWAP") {}

Swap::~Swap() {}

void Swap::executeAbility(Player *player, long long &pts, vector<Player *> players, DeckCards &deck, Turn &turn, map<Player *, Ability *> playerAbility)
{
    if (playerAbility[player]->getIsDisabled())
    {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya :(." << endl;
        cout << "Silahkan lakukan perintah lain." << endl;
        throw StillCurrentTurn();
    }
    else
    {
        cout << player->getName() << " melakukan SWAPCARD." << endl;

        vector<Player *> targetPlayers;
        for (Player *target : players)
        {
            if (target != player)
            {
                targetPlayers.push_back(target);
            }
        }
        Player *choosedPlayer = Ability::choosePlayer(targetPlayers, "SWAP", player);

        vector<Player *> targetPlayers2;
        for (Player *target : players)
        {
            if (target != player && target != choosedPlayer)
            {
                targetPlayers2.push_back(target);
            }
        }
        Player *choosedPlayer2 = Ability::choosePlayer(targetPlayers2, "SWAP2", player);

        PlayerCards card1 = choosedPlayer->getCards();
        PlayerCards card2 = choosedPlayer2->getCards();

        int pick1 = chooseHand(*choosedPlayer);
        int pick2 = chooseHand(*choosedPlayer2);

        Card hand1;
        Card hand2;

        if (pick1 == 1)
        {
            hand1 = card1.getRightCard();
        }
        else
        {
            hand1 = card1.getLeftCard();
        }

        if (pick2 == 1)
        {
            hand2 = card2.getRightCard();
        }
        else
        {
            hand2 = card2.getLeftCard();
        }

        if (pick1 == 1)
        {
            card1.setRightCard(hand2);
        }
        else
        {
            card1.setLeftCard(hand2);
        }

        if (pick2 == 1)
        {
            card2.setRightCard(hand1);
        }
        else
        {
            card2.setLeftCard(hand1);
        }
    }
}

int Swap::chooseHand(Player &player)
{
    bool validInput = false;
    int pick;
    while (!validInput)
    {
        std::cout << "Silakan pilih kartu kanan/kiri " << player.getName() << ":" << std::endl;
        std::cout << "1. Kanan" << std::endl;
        std::cout << "2. Kiri" << std::endl;
        string input;
        getline(cin, input);
        try
        {
            int choosedIndex = stoi(input);
            if (choosedIndex < 1 || choosedIndex > 2)
                throw PlayerDoesNotExist();
            pick = choosedIndex;
            validInput = true;
        }
        catch (...)
        {
            printf("Pilihan tidak valid, tolong pilih opsi yang diberikan\n");
        }
    }
    return pick;
}
