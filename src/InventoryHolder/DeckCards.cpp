#include "DeckCards.hpp"
#include "../Exception/Exception.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>

DeckCards::DeckCards()
    : InventoryHolder(52) {
    std::string validColor[] = {"hijau", "biru", "kuning", "merah"};
    for(std::string color : validColor){
        for(int i=1;i<=13;i++){
            insertCard(Card(i, color));
        }
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
        insertCard(card);
    }
    if(fin >> color)throw InvalidFileInputAmountException();
}
