#include "InventoryHolder.hpp"
#include "../Exception/Exception.h"
#include <algorithm>

// InventoryHolder::InventoryHolder(int lim) : limit(lim) {}

// InventoryHolder::InventoryHolder(const InventoryHolder &inventory)
//     : limit(inventory.limit)
// {
//     this->cards = inventory.cards;
// }

// InventoryHolder::~InventoryHolder() {}

// InventoryHolder InventoryHolder::operator=(const InventoryHolder &inventory)
// {
//     InventoryHolder newInventory(inventory);
//     return newInventory;
// }

// void InventoryHolder::clear()
// {
//     cards.clear();
// }

// void InventoryHolder::insertCard(Card card)
// {
//     if (cards.size() == limit)
//         throw InventoryFullException();
//     cards.push_back(card);
// }

// void InventoryHolder::removeCard(Card card)
// {
//     std::vector<Card>::iterator it = std::find(cards.begin(), cards.end(), card);
//     if (it == cards.end())
//         throw InventoryCardNotFoundException();
//     cards.erase(it);
// }

// Card InventoryHolder::getItem(int idx)
// {
//     if (idx >= cards.size())
//         throw InventoryOutOfBoundException();
//     return cards[idx];
// }

// int InventoryHolder::getSize()
// {
//     return cards.size();
// }

// InventoryHolder operator+(InventoryHolder &inventory, Card card)
// {
//     InventoryHolder newInventory(inventory);
//     newInventory.insertCard(card);
//     return newInventory;
// }

// InventoryHolder operator-(InventoryHolder &inventory, Card card)
// {
//     InventoryHolder newInventory(inventory);
//     newInventory.removeCard(card);
//     return newInventory;
// }

// InventoryHolder &operator+=(InventoryHolder &inventory, Card card){
//     inventory.insertCard(card);
//     return inventory;
// }
// InventoryHolder &operator-=(InventoryHolder &inventory, Card card){
//     inventory.removeCard(card);
//     return inventory;
// }

// std::istream &operator>>(std::istream &is, InventoryHolder &inventory)
// { // format : <color> <number>
//     // ! masih bisa duplikat
//     if (inventory.getSize() == inventory.limit)
//         throw InvalidFileInputAmountException();
//     std::string color;
//     int number;
//     if (!(is >> color))
//         throw InvalidFileInputNamingFormatException();
//     if (!(is >> number))
//         throw InvalidFileInputNamingFormatException();
//     std::vector<std::string> validColor = {"hijau", "biru", "kuning", "merah"};
//     if (find(validColor.begin(), validColor.end(), color) == validColor.end())
//         throw InvalidFileInputNamingFormatException();
//     if (number < 1 || number > 13)
//         throw InvalidFileInputNamingFormatException();
//     Card card(number, color);
//     inventory.insertCard(card);
//     return is;
// }