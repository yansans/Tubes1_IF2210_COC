#ifndef TABLECARDS_HPP
#define TABLECARDS_HPP

#include "InventoryHolder.hpp"
#include "DeckCards.hpp"
#include "../Storage/DeckStorage.hpp"

class TableCards : public InventoryHolder<Card>
{
public:
    TableCards();
    void drawCard();
    void displayCard();
};

#endif