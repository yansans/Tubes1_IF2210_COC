#ifndef PLAYERCARDS_HPP
#define PLAYERCARDS_HPP

#include "InventoryHolder.hpp"

class PlayerCards : public InventoryHolder<Card>
{
public:
    PlayerCards();
    Card getLeftCard();
    Card getRightCard();
    void setLeftCard(Card);
    void setRightCard(Card);
    void displayCard();
};

#endif