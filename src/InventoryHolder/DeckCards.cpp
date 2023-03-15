#include "DeckCards.hpp"
#include "../Exception/Exception.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include <set>


DeckCards::DeckCards()
    : InventoryHolder(52) {
    std::string validColor[] = {"hijau", "biru", "kuning", "merah"};
    std::vector<Card> cards;
    for(std::string color : validColor){
        for(int i=1;i<=13;i++){
            cards.push_back(Card(i, color));
        }
    }

    std::shuffle(cards.begin(), cards.end(), std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count()));
    for(int i=0;i<52;i++){
        insertItem(cards[i]);
    }
}

DeckCards::DeckCards(std::string fileName)
    : InventoryHolder(52) {
    std::ifstream fin(fileName);
    std::string color;
    int number;
    std::vector<std::string> validColor = {"hijau", "biru", "kuning", "merah"};
    std::set<Card> availableCard;
    for(int i=1;i<=13;i++){
        for(std::string color : validColor){
            availableCard.insert(Card(i, color));
        }
    }

    for(int i=0;i<52;i++){
        if(!(fin >> color))throw InvalidFileInputNamingFormatException();
        if(!(fin >> number))throw InvalidFileInputNamingFormatException();
        if(std::find(validColor.begin(), validColor.end(), color) == validColor.end())throw InvalidFileInputNamingFormatException();
        if(number < 1 || number > 13)throw InvalidFileInputNamingFormatException();
        Card card(number, color);
        bool alreadyExist = availableCard.find(card) == availableCard.end();
        if(alreadyExist)
            throw DuplicateCardException();
        insertItem(card);
        availableCard.erase(card);
    }
    if(fin >> color)throw InvalidFileInputAmountException();
}

std::istream &operator>>(std::istream &is, DeckCards &inventory)
{ // format : <color> <number>
    if (inventory.getSize() == inventory.limit)
        throw InvalidFileInputAmountException();

    std::string color;
    int number;
    if (!(is >> color))
        throw InvalidFileInputNamingFormatException();
    if (!(is >> number))
        throw InvalidFileInputNamingFormatException();

    std::vector<std::string> validColor = {"hijau", "biru", "kuning", "merah"};
    if (find(validColor.begin(), validColor.end(), color) == validColor.end())
        throw InvalidFileInputNamingFormatException();
    if (number < 1 || number > 13)
        throw InvalidFileInputNamingFormatException();

    Card card(number, color);
    bool alreadyExist = false;
    for(int i=0;i<inventory.getSize();i++){
        if(inventory.getItem(i) == card)alreadyExist = true;
    }
    if(alreadyExist)
        throw DuplicateCardException();
    inventory.insertItem(card);
    return is;
}