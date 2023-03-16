#include "AbilityHolder.hpp"
#include <set>

AbilityHolder::AbilityHolder() {}

AbilityHolder::AbilityHolder(vector<Player *> &players)
{
    for (int i = 0; i < players.size(); i++)
    {
        this->playerAbility[players[i]] = NULL;
    }
}

AbilityHolder::~AbilityHolder() {}

void AbilityHolder::addAbility(Player *player, Ability *ability)
{
    auto it = this->playerAbility.find(player);
    if (it == this->playerAbility.end())
    {
        throw PlayerDoesNotExist();
    }

    this->playerAbility[player] = ability;
}

void AbilityHolder::removeAbility(Player *player)
{
    auto it = this->playerAbility.find(player);
    if (it == this->playerAbility.end())
    {
        throw PlayerDoesNotExist();
    }

    if (playerAbility[player] != NULL)
    {
        delete this->playerAbility[player];
    }
}

bool AbilityHolder::playerHasAbility(Player *player, Ability *ability)
{
    return checkPlayerAbility(player) == ability;
}

Ability *AbilityHolder::checkPlayerAbility(Player *player)
{
    auto it = this->playerAbility.find(player);
    if (it == this->playerAbility.end())
    {
        throw PlayerDoesNotExist();
    }

    return this->playerAbility[player];
}

Player *AbilityHolder::checkAbilityOwner(Ability *ability)
{
    for (auto it = this->playerAbility.begin(); it != this->playerAbility.end(); it++)
    {
        if (it->second == ability)
        {
            return it->first;
        }
    }
    throw AbilityDoesNotFoundOrNull();
}

void AbilityHolder::executeAbility(string abilityString, Player *player, long long &pts, vector<Player *> players, DeckCards &deck, Turn &turn)
{
    const set<string> abilityCommand = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};
    if (abilityCommand.find(abilityString) == abilityCommand.end())
        throw InvalidCommand();
    if (playerAbility[player] == NULL || playerAbility[player]->getAbilityName() != abilityString)
    {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability " << abilityString << '.' << endl;
        throw StillCurrentTurn();
    }
    else
    {
        playerAbility[player]->executeAbility(player, pts, players, deck, turn, playerAbility);
        playerAbility[player]->setIsUsed(true);
    }
}