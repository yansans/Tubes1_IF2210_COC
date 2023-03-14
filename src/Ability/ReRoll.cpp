# include "ReRoll.hpp"

ReRoll::ReRoll() : Ability("RE-ROLL") {}

ReRoll::~ReRoll() {}

void ReRoll::executeAbility(Player* player, DeckCards& deck) {
    player->takeCards(deck);
}