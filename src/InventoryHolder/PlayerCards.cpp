#include "PlayerCards.hpp"
#include "../Exception/Exception.h"

PlayerCards::PlayerCards()
    : InventoryHolder(2) {}

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
    std::cout << getLeftCard();
    std::cout << " && ";
    std::cout << getRightCard();
    std::cout << std::endl;
}

void PlayerCards::setLeftCard(Card card)
{
    if (getSize() == 0)
    {
        this->insertItem(card);
    }
    else if (getSize() == 1)
    {
        this->removeItem(this->getItem(0));
        this->insertItem(card);
    }
    else
    {
        Card right = this->getItem(1);
        this->removeItem(this->getItem(1));
        this->removeItem(this->getItem(0));
        this->insertItem(card);
        this->insertItem(right);
    }
}

void PlayerCards::setRightCard(Card card)
{
    if (getSize() == 0)
    {
        throw InventoryOutOfBoundException();
    }
    else if (getSize() == 1)
    {
        this->insertItem(card);
    }
    else
    {
        this->removeItem(this->getItem(1));
        this->insertItem(card);
    }
}