#include "../Card.hpp"
#include "../Combo.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<Card> cards1;
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(4, "kuning"));
    cards1.push_back(Card(5, "kuning"));
    cards1.push_back(Card(5, "merah"));

    Combo combo1(cards1);

    cout << combo1.get_combo_type() << endl;

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(2, "biru"));
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(5, "merah"));
    cards1.push_back(Card(4, "biru"));
    cards1.push_back(Card(6, "hijau"));

    combo1 = Combo(cards1);

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(5, "kuning"));
    cards1.push_back(Card(4, "kuning"));
    cards1.push_back(Card(6, "kuning"));

    combo1 = Combo(cards1);

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(1, "biru"));
    cards1.push_back(Card(3, "merah"));
    cards1.push_back(Card(1, "merah"));
    cards1.push_back(Card(3, "biru"));
    cards1.push_back(Card(2, "kuning"));

    combo1 = Combo(cards1);

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(1, "biru"));

    combo1 = Combo(cards1);

    cout << combo1.get_value() << endl;

    return 0;
}