#include "../Card.hpp"
#include "../Combo.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<Card> cards1;
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(3, "biru"));

    Combo combo1(cards1);

    combo1.print_type();
    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(11, "merah"));
    cards1.push_back(Card(3, "hijau"));
    cards1.push_back(Card(5, "biru"));
    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(11, "kuning"));
    cards1.push_back(Card(7, "merah"));
    cards1.push_back(Card(1, "kuning"));

    combo1 = Combo(cards1);

    combo1.print_type();
    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(5, "hijau"));
    cards1.push_back(Card(10, "merah"));
    cards1.push_back(Card(5, "biru"));
    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(11, "kuning"));
    cards1.push_back(Card(7, "merah"));
    cards1.push_back(Card(1, "kuning"));

    combo1 = Combo(cards1);

    combo1.print_type();
    cout << combo1.get_value() << endl;

    // cards1.clear();

    // cards1.push_back(Card(2, "merah"));
    // cards1.push_back(Card(3, "kuning"));
    // cards1.push_back(Card(1, "biru"));
    // cards1.push_back(Card(3, "merah"));
    // cards1.push_back(Card(1, "merah"));
    // cards1.push_back(Card(3, "biru"));
    // cards1.push_back(Card(2, "kuning"));

    // combo1 = Combo(cards1);

    // combo1.print_type();
    // cout << combo1.get_value() << endl;

    // cards1.clear();

    // cards1.push_back(Card(2, "merah"));
    // cards1.push_back(Card(3, "kuning"));
    // cards1.push_back(Card(1, "biru"));

    // combo1 = Combo(cards1);

    // combo1.print_type();
    // cout << combo1.get_value() << endl;

    return 0;
}