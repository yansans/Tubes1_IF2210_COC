#include "./Player/Player.hpp"
#include "./Turn/Turn.hpp"
#include "bits/stdc++.h"



using namespace std;

int main()
{
    vector<Player *> v;
    Player p1("brian"), p2("dewa"), p3("miku"), p4("sano"), p5("rayhan"), p6("yuki"), p7("kato");
    DeckCards deck;
    cout << deck.getSize() << endl;
    cout << deck.getItem(0) << endl;
    cout << deck.getItem(1) << endl;
    cout << p1.getCards().getSize() << endl;
    p1.takeCards(deck);
    cout << p1.getCards().getLeftCard() << endl;
    cout << p1.getCards().getRightCard() << endl;
    cout << deck.getItem(0) << endl;
    cout << deck.getItem(1) << endl;
    cout << deck.getSize() << endl;
    p1.reset(deck);
    cout << p1.getCards().getSize() << endl;
    cout << deck.getSize() << endl;
    /*
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    v.push_back(&p6);
    v.push_back(&p7);
    Turn t(v);
    Player *curPlayer = t.currentTurn();
    cout << t.getRound() << endl;
    cout << curPlayer->getName() << endl;
    // curPlayer->addPoint(10);
    // cout << p1.getPoint() << endl;
    for (int i = 0; i < 2; i++)
    {
        Player *curPlayer = t.nextTurn();
        cout << t.getRound() << endl;
        cout << curPlayer->getName() << endl;
    }
    // Miku
    t.reverse();

    cout << t.currentTurn()->getName() << endl; // bug!! Expected Miku, found Brian!

    for (int i = 0; i < 16; i++)
    {
        Player *curPlayer = t.nextTurn();
        cout << t.getRound() << endl;
        cout << curPlayer->getName() << endl;
    }
    */
    return 0;
}

// g++ -o tes tes.cpp ./Player/Player.cpp ./Turn/Turn.cpp ./InventoryHolder/PlayerCards.cpp ./InventoryHolder/InventoryHolder.cpp ./Values/Card.cpp ./InventoryHolder/DeckCards.cpp