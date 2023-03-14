#ifndef TABLECARDS_HPP
#define TABLECARDS_HPP

#include "InventoryHolder.hpp"
#include "DeckCards.hpp"

class TableCards : public InventoryHolder{
public:
    TableCards();
    void drawCard(DeckCards);
    void displayCard();
};

#endif