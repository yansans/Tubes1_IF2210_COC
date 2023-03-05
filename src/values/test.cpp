#include "card.cpp"
// import card sama combo kalo misah error jdi disatuin dulu
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<Card> cards;
    cards.push_back(Card(1, "biru"));
    cards.push_back(Card(2, "biru"));
    cards.push_back(Card(3, "merah"));
    cards.push_back(Card(4, "merah"));
    cards.push_back(Card(5, "biru"));
    cards.push_back(Card(7, "biru"));
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
    if (combo2.flush_check()) cout << "Flush" << endl;
    else cout << "Not Flush" << endl;
    if (combo2.straight_check()) cout << "Straight" << endl;
    else cout << "Not Straight" << endl;
    if (combo2.fourkind_check()) cout << "Fourkind" << endl;
    else cout << "Not Fourkind" << endl;
    if (combo2.threekind_check()) cout << "Threekind" << endl;
    else cout << "Not Threekind" << endl;
    if (combo2.pair_check()) cout << "Pair" << endl;
    else cout << "Not Pair" << endl;

    return 0;
}