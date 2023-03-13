#include "../InventoryHolder.hpp"
#include "../PlayerCards.hpp"
#include "../TableCards.hpp"
#include "../DeckCards.hpp"
#include "../../Exception/Exception.h"

/*
compile : 
g++ ../*.cpp ../../values/card.cpp test.cpp -o test
./test
*/

#include <iostream>
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
    }catch(InventoryOutOfBoundException e){
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
    DeckCards dc;

    testerroraccess(ih, 5);

    Card b2(2, "blue");
    Card b3(3, "blue");
    testerrorremove(ih, b2);

    range(i,0,3)ih.insertCard(b2);
    printcard(ih.getItem(2));

    testerrorinsert(ih, b2);
    testerrorremove(ih, b3);

    range(i,0,2)pc.insertCard(b2);
    range(i,0,5)tc.insertCard(b2);

    testerrorinsert(pc, b3);
    testerrorinsert(tc, b3);
    testerrorinsert(dc, b3);
    
    return 0;
}