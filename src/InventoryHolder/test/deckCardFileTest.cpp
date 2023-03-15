#include "../InventoryHolder.hpp"
#include "../../Values/Card.cpp"
#include "../DeckCards.cpp"
#include "../../Exception/Exception.h"

#include <iostream>
#include <fstream>
#define print(var)  std::cout << (var) << std::endl;
#define range(i,s,e) for(int i=s;i<e;i++)
#define debug       print("debug")

void testerrorfile(string path){
    try{
        DeckCards dce(path);
        print("gak error")
    }catch(exception& e){
        print(e.what())
    }
}

void printcard(Card card){
    std::cout << card.get_colour() << " " << card.get_number() << std::endl;
}

int main(){
    testerrorfile("testFstreamGood.txt");
    testerrorfile("testFstreamGood2.txt");
    testerrorfile("testFstreamTooMuch.txt");
    testerrorfile("testFstreamFew.txt");
    testerrorfile("testFstreamDuplicate.txt");
    testerrorfile("testFstreamDuplicate2.txt");


    
    return 0;
}