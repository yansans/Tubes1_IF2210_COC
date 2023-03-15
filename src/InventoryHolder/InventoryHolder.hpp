#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include <algorithm>
#include "../Exception/Exception.h"
#include "../Values/Card.hpp"

template<class T>
class InventoryHolder
{
private:
    std::vector<T> cards;
    const int limit;

public:
    InventoryHolder(int lim): limit(lim) {}
    InventoryHolder(const InventoryHolder &inventory): limit(inventory.limit) {
        this->cards = inventory.cards;
    }
    ~InventoryHolder() {}
    InventoryHolder operator=(const InventoryHolder &inventory) { // ! childnya harus bikin lagi
        InventoryHolder newInventory(inventory);
        return newInventory;
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
    friend std::istream &operator>>(std::istream &is, InventoryHolder &inventory)
    { // format : <color> <number>
        // ! masih bisa duplikat
        // if (inventory.getSize() == inventory.limit)
        //     throw InvalidFileInputAmountException();
        // std::string color;
        // int number;
        // if (!(is >> color))
        //     throw InvalidFileInputNamingFormatException();
        // if (!(is >> number))
        //     throw InvalidFileInputNamingFormatException();
        // std::vector<std::string> validColor = {"hijau", "biru", "kuning", "merah"};
        // if (find(validColor.begin(), validColor.end(), color) == validColor.end())
        //     throw InvalidFileInputNamingFormatException();
        // if (number < 1 || number > 13)
        //     throw InvalidFileInputNamingFormatException();
        // T card(number, color);
        // inventory.insertCard(card);
        return is;
    }
    void displayCard();
    void clear() {
        cards.clear();
    }
};

#endif