#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "../values/card.hpp"

class InventoryHolder{
private:
    vector<Card> cards;
    const int limit;
public:
    InventoryHolder(int);
    ~InventoryHolder();
    void insertCard(Card);
    void removeCard(Card);
    Card getItem(int);
    int getSize();
};

#endif