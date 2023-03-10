#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct InventoryFullException : public exception {
    const char* what() const throw() {
        return "Can't insert card, Inventory is full";
    }
};

struct InventoryCardNotFoundException : public exception {
    const char* what() const throw() {
        return "Can't remove card, card not found in inventory";
    }
};

struct InventoryOutOfBoundException : public exception {
    const char* what() const throw() {
        return "There is no item in this index";
    }
};


#endif