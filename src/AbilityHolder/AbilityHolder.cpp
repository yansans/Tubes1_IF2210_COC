# include "AbilityHolder.hpp"

AbilityHolder::AbilityHolder(vector<Player*> players) {
    for(int i = 0; i < players.size(); i++) {
        this->playerAbility[players[i]] = NULL;
    }
}

AbilityHolder::~AbilityHolder() {}

void AbilityHolder::addAbility(Player* player, Ability* ability) {
    auto it = this->playerAbility.find(player);
    if(it == this->playerAbility.end()) {
        throw PlayerDoesNotExist();
    }

    this->playerAbility[player] = ability;
}

void AbilityHolder::removeAbility(Player* player) {
    auto it = this->playerAbility.find(player);
    if(it == this->playerAbility.end()) {
        throw PlayerDoesNotExist();
    }

    this->playerAbility[player] = NULL;
}

bool AbilityHolder::checkPlayerHasAbility(Player* player, Ability* ability) {
    auto it = this->playerAbility.find(player);
    if(it == this->playerAbility.end()) {
        throw PlayerDoesNotExist();
    }
    return this->playerAbility[player] == ability;
}

Player* AbilityHolder::checkAbilityOwner(Ability* ability) {
    for(auto it = this->playerAbility.begin(); it != this->playerAbility.end(); it++) {
        if(it->second == ability) {
            return it->first;
        }
    }
    throw AbilityDoesNotFoundOrNull();
}