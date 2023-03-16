#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

struct InventoryFullException : public exception {
    const char* what() const throw() {
        return "Can't insert item, Inventory is full";
    }
};

struct InventoryItemNotFoundException : public exception {
    const char* what() const throw() {
        return "Can't remove item, item not found in inventory";
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

struct InvalidOptionInputException : public exception {
    const char* what() const throw() {
        return "Please choose correct option";
    }
};

struct InvalidFileNameException : public exception {
    const char* what() const throw() {
        return "Filepath not found";
    }
};

struct PlayerDoesNotExist : public exception {
    const char* what() const throw() {
        return "There is no such player";
    }
};

struct AbilityDoesNotFoundOrNull : public exception {
    const char* what() const throw() {
        return "No such Ability";
    }
};

struct EmptyContainerException : public exception {
    const char* what() const throw() {
        return "Empty container!";
    }
};

struct InvalidAbility : public exception {
    const char* what() const throw() {
        return "Invalid Ability";
    }
};

struct StillCurrentTurn : public exception {
    const char* what() const throw() {
        return "Continue to current turn";
    }
};

struct DuplicateCardException : public exception {
    const char* what() const throw() {
        return "Duplicate Card Detected!";
    }
};

struct ParticipantCountAboveLimit : public exception {
    const char* what() const throw() {
        return "Participant count cannot exceed limit";
    }
};

#endif