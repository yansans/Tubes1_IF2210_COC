#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include "../values/card.hpp"

class InventoryHolder{ // ! belum abstact
private:
    std::vector<Card> cards;
    const int limit;
public:
    InventoryHolder(int);
    InventoryHolder(const InventoryHolder&);
    ~InventoryHolder();
    InventoryHolder operator= (const InventoryHolder&); // ! childnya harus bikin lagi, gak DRY
    void insertCard(Card);
    void removeCard(Card);
    Card getItem(int);
    int getSize();
    friend InventoryHolder operator+ (InventoryHolder&, Card);
    friend InventoryHolder operator- (InventoryHolder&, Card);
    friend std::istream& operator>> (std::istream&, InventoryHolder&);
};

#endif