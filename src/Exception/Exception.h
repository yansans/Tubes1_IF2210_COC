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

struct InvalidFileInputNamingFormatException : public exception {
    const char* what() const throw() {
        return "Invalid card naming format";
    }
};

struct InvalidFileInputAmountException : public exception {
    const char* what() const throw() {
        return "Too much card in your input";
    }
};

struct InvalidCardNumber : public exception {
    const char* what() const throw() {
        return "Your card number is not valid";
    }
};

struct InvalidCardColour : public exception {
    const char* what() const throw() {
        return "Your card colour is not valid";
    }
};

struct InvalidCommand : public exception {
    const char* what() const throw() {
        return "Invalid Command";
    }
};

#endif