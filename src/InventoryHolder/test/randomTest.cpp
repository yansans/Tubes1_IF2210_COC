#include "../InventoryHolder.hpp"
#include "../PlayerCards.hpp"
#include "../TableCards.hpp"
#include "../DeckCards.hpp"
#include "../../Exception/Exception.h"

/*
compile : 
g++ ../*.cpp ../../values/card.cpp randomTest.cpp -o test
./test

*/

#include <iostream>
#include <fstream>
#define print(var)  std::cout << (var) << std::endl;
#define range(i,s,e) for(int i=s;i<e;i++)
#define debug       print("debug")

void printcard(Card card1, Card card2){
    std::cout << card1.get_colour() << " " << card1.get_number() 
    << "  \t" << card2.get_colour() << " " << card2.get_number() << std::endl;
}

int main(){
    DeckCards dc1;
    DeckCards dc2;
    print("Deck 1 : \tDeck 2 : ")
    range(i,0,52){
        printcard(dc1.getItem(i), dc2.getItem(i));
    }

    
    return 0;
}