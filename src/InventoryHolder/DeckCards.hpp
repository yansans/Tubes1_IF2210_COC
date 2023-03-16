#ifndef DECKCARDS_HPP
#define DECKCARDS_HPP

#include "InventoryHolder.hpp"
#include "../Values/Values.hpp"

class DeckCards : public InventoryHolder<Card>
{
public:
    DeckCards();
    DeckCards(std::string);
    friend std::istream &operator>>(std::istream &is, DeckCards &inventory);
};

#endif