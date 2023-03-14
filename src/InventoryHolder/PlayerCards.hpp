#ifndef PLAYERCARDS_HPP
#define PLAYERCARDS_HPP

#include "InventoryHolder.hpp"

class PlayerCards : public InventoryHolder{
public:
    PlayerCards();
    Card getLeftCard();
    Card getRightCard();
    void displayCard();
};

#endif