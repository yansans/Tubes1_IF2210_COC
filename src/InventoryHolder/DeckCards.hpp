#ifndef DECKCARDS_HPP
#define DECKCARDS_HPP

#include "InventoryHolder.hpp"
#include "../Values/Values.hpp"

class DeckCards : public InventoryHolder<Card>{
public:
    DeckCards();
    DeckCards(std::string);
};



#endif