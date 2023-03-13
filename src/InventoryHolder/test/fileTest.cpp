#include "../InventoryHolder.hpp"
#include "../PlayerCards.hpp"
#include "../TableCards.hpp"
#include "../DeckCards.hpp"
#include "../../Exception/Exception.h"

/*
compile : 
g++ ../*.cpp ../../values/card.cpp fileTest.cpp -o test
./test
*/

#include <iostream>
#include <fstream>
#define print(var)  std::cout << (var) << std::endl;
#define range(i,s,e) for(int i=s;i<e;i++)
#define debug       print("debug")

void testerrorinsert(InventoryHolder& ih, Card card){
    try{
        ih.insertCard(card);
        print("gak error")
    }catch(InventoryFullException e){
        print(e.what())
    }
}

void testerrorremove(InventoryHolder& ih, Card card){
    try{
        ih.removeCard(card);
        print("gak error")
    }catch(InventoryCardNotFoundException e){
        print(e.what())
    }
}

void testerroraccess(InventoryHolder& ih, int idx){
    try{
        ih.getItem(idx);
        print("gak error")
    }catch(InventoryCardNotFoundException e){
        print(e.what())
    }
}

void testerrorinput(InventoryHolder& ih, std::ifstream& is){
    try{
        is >> ih;
        print("gak error")
    }catch(InvalidFileInputNamingFormatException e){
        print(e.what())
    }
}

void printcard(Card card){
    std::cout << card.get_colour() << " " << card.get_number() << std::endl;
}

int main(){
    InventoryHolder ih(3);
    PlayerCards pc;
    TableCards tc;

    std::ifstream test1("testIstream.txt");
    std::ifstream test2("testIstreamError.txt");
    // ! masih kurang edge case

    test1 >> pc;
    test1 >> tc;

    printcard(pc.getItem(0));
    printcard(tc.getItem(0));

    testerrorinput(pc, test2);

    DeckCards dc("testFstream.txt");
    printcard(dc.getItem(14));

    try{
        DeckCards dce("testFstreamError.txt");
        print("gak error")
    }catch(InvalidFileInputNamingFormatException e){
        print(e.what())
    }


    
    return 0;
}