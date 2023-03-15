#include "DeckCards.hpp"
#include "../Exception/Exception.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>


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
    // ! masih bisa duplikat
    std::ifstream fin(fileName);
    std::string color;
    int number;
    std::vector<std::string> validColor = {"hijau", "biru", "kuning", "merah"};

    for(int i=0;i<52;i++){
        if(!(fin >> color))throw InvalidFileInputNamingFormatException();
        if(!(fin >> number))throw InvalidFileInputNamingFormatException();
        if(std::find(validColor.begin(), validColor.end(), color) == validColor.end())throw InvalidFileInputNamingFormatException();
        if(number < 1 || number > 13)throw InvalidFileInputNamingFormatException();
        Card card(number, color);
        insertItem(card);
    }
    if(fin >> color)throw InvalidFileInputAmountException();
}

std::istream &operator>>(std::istream &is, DeckCards &inventory)
{ // format : <color> <number>
    // ! masih bisa duplikat
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
    inventory.insertItem(card);
    return is;
}