#include "Ability.hpp"
#include "../Exception/Exception.h"

Ability::Ability(string name)
{
    this->name = name;
    this->isUsed = false;
    this->isDisabled = false;
}

Ability::~Ability() {}

string Ability::getAbilityName() const
{
    return this->name;
}

void Ability::setIsUsed(bool isUsed)
{
    this->isUsed = isUsed;
}

bool Ability::getIsUsed()
{
    return this->isUsed;
}

void Ability::setIsDisabled(bool isDisabled)
{
    this->isDisabled = isDisabled;
}

bool Ability::getIsDisabled()
{
    return this->isDisabled;
}
Player *Ability::choosePlayer(vector<Player *> targetPlayers, string abilityName, Player *player)
{
    bool validInput = false;
    Player *choosedPlayer;
    while (!validInput)
    {
        if (abilityName == "ABILITYLESS")
        {
            cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << endl;
        }
        else if (abilityName == "SWAP")
        {
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        }
        else if (abilityName == "SWAP2")
        {
            cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
        }
        else if (abilityName == "SWITCH")
        {
            player->getCards().displayCard();
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
        }
        else
        {
            throw AbilityDoesNotFoundOrNull();
        }
        for (int i = 0; i < targetPlayers.size(); i++)
        {
            cout << i + 1 << ". " << targetPlayers[i]->getName() << endl;
        }
        string input;
        getline(cin, input);
        try
        {
            int choosedIndex = stoi(input);
            if (choosedIndex < 1 || choosedIndex > targetPlayers.size())
                throw PlayerDoesNotExist();
            choosedPlayer = targetPlayers[choosedIndex - 1];
            validInput = true;
        }
        catch (...)
        {
            printf("Pilihan tidak valid, tolong pilih opsi yang diberikan\n");
        }
    }
    return choosedPlayer;
}
