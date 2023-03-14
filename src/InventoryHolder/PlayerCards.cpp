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

void PlayerCards::displayCard()
{
    std::cout << "Kartumu sekarang adalah:" << std::endl;
    std::cout << getLeftCard().get_number() << " (" << getLeftCard().get_colour() << ")";
    std::cout << " && ";
    std::cout << getRightCard().get_number() << " (" << getRightCard().get_colour() << ")";
    std::cout << std::endl;
}