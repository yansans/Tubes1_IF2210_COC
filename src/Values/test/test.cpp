#include "../Card.hpp"
#include "../Combo.hpp"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<Card> cards1;
    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(2, "biru"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(3, "biru"));
    cards1.push_back(Card(2, "hijau"));

    Combo combo1(cards1);

    // cout << combo1.pair_check(0).first << endl;
    // cout << combo1.pair_check(0).second << endl;

    if (combo1.is_pair()){
        cout << combo1.get_pair() << endl;
    } else {
        cout << "bukan pair" << endl;
    }

    // cout << combo1.threekind_check(0).first << endl;
    // cout << combo1.threekind_check(0).second << endl;

    if (combo1.is_threekind()){
        cout << combo1.get_threekind() << endl;
    } else {
        cout << "bukan threekind" << endl;
    }

    // cout << combo1.fourkind_check().first << endl;
    // cout << combo1.fourkind_check().second << endl;

    if (combo1.is_fourkind()){
        cout << combo1.get_fourkind() << endl;
    } else {
        cout << "bukan fourkind" << endl;
    }

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(2, "biru"));
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(5, "merah"));
    cards1.push_back(Card(4, "biru"));
    cards1.push_back(Card(6, "hijau"));

    combo1 = Combo(cards1);

    // cout << combo1.straight_check().first << endl;
    // cout << combo1.straight_check().second << endl;

    if (combo1.is_straight()){
        cout << combo1.get_straight() << endl;
    } else {
        cout << "bukan straight" << endl;
    }

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(2, "kuning"));
    cards1.push_back(Card(1, "kuning"));
    cards1.push_back(Card(5, "kuning"));
    cards1.push_back(Card(4, "kuning"));
    cards1.push_back(Card(6, "kuning"));

    combo1 = Combo(cards1);

    // cout << combo1.flush_check().first << endl;
    // cout << combo1.flush_check().second << endl;

    if (combo1.is_flush()){
        cout << combo1.get_flush() << endl;
    } else {
        cout << "bukan flush" << endl;
    }

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

    // cout << combo1.fullhouse_check().first << endl;
    // cout << combo1.fullhouse_check().second.first << endl;
    // cout << combo1.fullhouse_check().second.second << endl;

    if (combo1.is_fullhouse()){
        cout << combo1.get_fullhouse().first << endl;
        cout << combo1.get_fullhouse().second << endl;
    } else {
        cout << "bukan fullhouse" << endl;
    }

    cout << combo1.get_value() << endl;

    cards1.clear();

    cards1.push_back(Card(2, "merah"));
    cards1.push_back(Card(3, "kuning"));
    cards1.push_back(Card(1, "biru"));

    combo1 = Combo(cards1);

    // cout << combo1.twopair_check().first << endl;
    // cout << combo1.twopair_check().second.first << endl;
    // cout << combo1.twopair_check().second.second << endl;

    if (combo1.is_twopair()){
        cout << combo1.get_twopair().first << endl;
        cout << combo1.get_twopair().second << endl;
    } else {
        cout << "bukan twopair" << endl;
    }

    cout << combo1.get_value() << endl;

    return 0;
}