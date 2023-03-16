#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <vector>
#include <algorithm>
#include "../Exception/Exception.h"
#include "../Values/Card.hpp"

template <class T>
class InventoryHolder
{
protected:
    std::vector<T> items;
    const int limit;

public:
    InventoryHolder(int lim) : limit(lim) {}
    InventoryHolder(const InventoryHolder &inventory) : limit(inventory.limit)
    {
        this->items = inventory.items;
    }
    ~InventoryHolder() {}
    InventoryHolder &operator=(const InventoryHolder &inventory)
    {
        this->items = inventory.items;
        return *this;
    }
    void insertItem(T item)
    {
        if (items.size() == limit)
            throw InventoryFullException();
        items.push_back(item);
    }
    void removeItem(T item)
    {
        typename std::vector<T>::iterator it = std::find(items.begin(), items.end(), item);
        if (it == items.end())
            throw InventoryItemNotFoundException();
        items.erase(it);
    }
    T getItem(int idx)
    {
        if (idx >= items.size())
            throw InventoryOutOfBoundException();
        return items[idx];
    }
    int getSize()
    {
        return items.size();
    }
    friend InventoryHolder operator+(InventoryHolder &inventory, T item)
    {
        InventoryHolder newInventory(inventory);
        newInventory.insertItem(item);
        return newInventory;
    }
    friend InventoryHolder operator-(InventoryHolder &inventory, T item)
    {
        InventoryHolder newInventory(inventory);
        newInventory.removeItem(item);
        return newInventory;
    }
    friend InventoryHolder &operator+=(InventoryHolder &inventory, T item)
    {
        inventory.insertItem(item);
        return inventory;
    }
    friend InventoryHolder &operator-=(InventoryHolder &inventory, T item)
    {
        inventory.removeItem(item);
        return inventory;
    }
    void displayItem();
    void clear()
    {
        items.clear();
    }
};

#endif