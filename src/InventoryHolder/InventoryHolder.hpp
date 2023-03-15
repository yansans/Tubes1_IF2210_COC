#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include <algorithm>
#include "../Exception/Exception.h"
#include "../Values/Card.hpp"

template<class T>
class InventoryHolder
{
protected:
    std::vector<T> cards;
    const int limit;

public:
    InventoryHolder(int lim): limit(lim) {}
    InventoryHolder(const InventoryHolder &inventory): limit(inventory.limit) {
        this->cards = inventory.cards;
    }
    ~InventoryHolder() {}
    InventoryHolder& operator=(const InventoryHolder &inventory){
        this->cards = inventory.cards;
        return *this;
    }
    void insertCard(T card) {
        if (cards.size() == limit)
            throw InventoryFullException();
        cards.push_back(card);
    }
    void removeCard(T card) {
        typename std::vector<T>::iterator it = std::find(cards.begin(), cards.end(), card);
        if (it == cards.end())
            throw InventoryCardNotFoundException();
        cards.erase(it);
    }
    T getItem(int idx) {
        if (idx >= cards.size())
            throw InventoryOutOfBoundException();
        return cards[idx];
    }
    int getSize() {
        return cards.size();
    }
    friend InventoryHolder operator+(InventoryHolder &inventory, T card)
    {
        InventoryHolder newInventory(inventory);
        newInventory.insertCard(card);
        return newInventory;
    }
    friend InventoryHolder operator-(InventoryHolder &inventory, T card)
    {
        InventoryHolder newInventory(inventory);
        newInventory.removeCard(card);
        return newInventory;
    }
    friend InventoryHolder &operator+=(InventoryHolder &inventory, T card){
        inventory.insertCard(card);
        return inventory;
    }
    friend InventoryHolder &operator-=(InventoryHolder &inventory, T card){
        inventory.removeCard(card);
        return inventory;
    }
    void displayCard();
    void clear() {
        cards.clear();
    }
};

#endif