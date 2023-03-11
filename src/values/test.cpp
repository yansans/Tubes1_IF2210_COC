#include "Card.hpp"
#include "Combo.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<Card> cards;
    cards.push_back(Card(2, "biru"));
    cards.push_back(Card(1, "biru"));
    cards.push_back(Card(1, "merah"));
    cards.push_back(Card(4, "merah"));
    cards.push_back(Card(5, "biru"));
    cards.push_back(Card(3, "biru"));
    cout << cards[0].get_value() << endl;
    cout << cards.size() << endl;
    Combo combo1(cards);
    if (combo1.flush_check()) cout << "Flush" << endl;
    else cout << "Not Flush" << endl;
    if (combo1.straight_check()) cout << "Straight" << endl;
    else cout << "Not Straight" << endl;

    cards.clear();

    cards.push_back(Card(7, "biru"));
    cards.push_back(Card(1, "merah"));
    cards.push_back(Card(1, "kuning"));
    cards.push_back(Card(2, "hijau"));
    cards.push_back(Card(2, "biru"));
    cards.push_back(Card(7, "biru"));
    cards.push_back(Card(1, "merah"));
    cout << cards[0].get_value() << endl;
    Combo combo2(cards);
    if (combo2.twopair_check()) cout << "Two Pair" << endl;
    else cout << "Not Two Pair" << endl;
    if (combo2.fullhouse_check()) cout << "Full House" << endl;
    else cout << "Not Full House" << endl;

    return 0;
}