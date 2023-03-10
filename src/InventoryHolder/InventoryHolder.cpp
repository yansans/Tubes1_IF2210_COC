#include "InventoryHolder.hpp"
#include "../Exception/Exception.h"
#include <algorithm>

InventoryHolder::InventoryHolder(int lim) : limit(lim){ }

InventoryHolder::~InventoryHolder() { }

void InventoryHolder::insertCard(Card card)
{
    if(cards.size() == limit)throw InventoryFullException();
    cards.push_back(card);
}

void InventoryHolder::removeCard(Card card)
{
    std::vector<Card>::iterator it = std::find(cards.begin(), cards.end(), card);
    if(it == cards.end())throw InventoryCardNotFoundException();
    cards.erase(it);
}

Card InventoryHolder::getItem(int idx)
{
    if(idx >= cards.size())throw InventoryOutOfBoundException();
    return cards[idx];
}

int InventoryHolder::getSize()
{
    return cards.size();
}