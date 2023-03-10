#include "PlayerCards.hpp"

PlayerCards::PlayerCards()
    : InventoryHolder(2) { }

Card PlayerCards::getLeftCard()
{
    return getItem(0);
}

Card PlayerCards::getRightCard()
{
    return getItem(1);
}
