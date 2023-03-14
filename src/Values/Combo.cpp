#include "Combo.hpp"
#include <string>
#include <algorithm>

using namespace std;

Combo::Combo(vector<Card> _cards){
    cards = _cards;
}

Combo& Combo::operator=(const Combo &other){
    cards = other.cards;
    return *this;
}

Combo::~Combo(){}

vector<Card> Combo::get_cards() const{
    return cards;
}
 
bool Combo::operator<(const Combo &other) const{
    return get_value() < other.get_value();
}

bool Combo::operator>(const Combo &other) const{
    return get_value() > other.get_value();
}

bool Combo::operator==(const Combo &other) const{
    return get_value() == other.get_value();
}


int Combo::get_combo_type() const{
    if (cards.size() >= 5 && straightflush_check().first) return 9;
    if (cards.size() >= 4 && fourkind_check().first) return 8;
    if (cards.size() >= 5 && fullhouse_check().first) return 7;
    if (cards.size() >= 5 && flush_check().first) return 6;
    if (cards.size() >= 5 && straight_check().first) return 5;
    if (cards.size() >= 3 && threekind_check().first) return 4;
    if (cards.size() >= 4 && twopair_check().first) return 3;
    if (cards.size() >= 2 && pair_check().first) return 2;
    return 1;
}

Card Combo::get_straightflush() const{
    return straightflush_check().second;
}

Card Combo::get_fourkind() const{
    return fourkind_check().second;
}

pair<Card,Card> Combo::get_fullhouse() const{
    return fullhouse_check().second;
}

Card Combo::get_flush() const{
    return flush_check().second;
}

Card Combo::get_straight() const{
    return straight_check().second;
}

Card Combo::get_threekind(int duplicate) const{
    return threekind_check(duplicate).second;
}

pair<Card,Card> Combo::get_twopair() const{
    return twopair_check().second;
}

Card Combo::get_pair(int duplicate) const{
    return pair_check(duplicate).second;
}

Card Combo::get_highcard() const{
    auto copy_cards = get_cards();
    sort(copy_cards.begin(), copy_cards.end());
    return copy_cards[copy_cards.size()-1];
}

template<>
Card Combo::get_combo_card() const{
    int type = get_combo_type();
    switch (type){
        case 1:
            return get_highcard();
            break;
        case 2:
            return get_pair();
            break;
        case 4:
            return get_threekind();
            break;
        case 5:
            return get_straight();
            break;
        case 6:
            return get_flush();
            break;
        case 8:
            return get_fourkind();
            break;
        case 9:
            return get_straightflush();
            break;
    }
    throw "No such combo";
}

template<>
pair<Card,Card> Combo::get_combo_card() const{
    int type = get_combo_type();
    switch (type){
        case 3:
            return get_twopair();
            break;
        case 7:
            return get_fullhouse();
            break;
    }
    throw "No such combo";
}

double Combo::get_value() const{
    double value = 0;
    int type = get_combo_type();
    switch (type){
        case 1:
            value = highcard_value();
            break;
        case 2:
            value = pair_value();
            break;
        case 3:
            value = twopair_value();
            break;
        case 4:
            value = threekind_value();
            break;
        case 5:
            value = straight_value();
            break;
        case 6:
            value = flush_value();
            break;
        case 7:
            value = fullhouse_value();
            break;
        case 8:
            value = fourkind_value();
            break;
        case 9:
            value = straightflush_value();
            break;
    }
    return value;
}

void Combo::print_type() const{
    int type = get_combo_type();
    switch (type){
        case 1:
            cout << "High card" << endl;
            break;
        case 2:
            cout << "Pair" << endl;
            break;
        case 3:
            cout << "Two pair" << endl;
            break;
        case 4:
            cout << "Three of a kind" << endl;
            break;
        case 5:
            cout << "Straight" << endl;
            break;
        case 6:
            cout << "Flush" << endl;
            break;
        case 7:
            cout << "Full house" << endl;
            break;
        case 8:
            cout << "Four of a kind" << endl;
            break;
        case 9:
            cout << "Straight flush" << endl;
            break;
    }
}

double Combo::get_draw_value() const{
    double new_value = 0;
    int type = get_combo_type();
    if (type == 9 || type == 8 || type == 6 || type == 5) {
        // straight flush, four of a kind, flush, straight
        if (threekind_check().first) new_value = threekind_value();
        else if (twopair_check().first) new_value = twopair_value();
        else if (pair_check().first) new_value = pair_value();
        else new_value = highcard_value();
    }
    else if (type == 7){
        // full house
        auto duplicate = get_combo_card<pair<Card,Card>>();
        int three_num = duplicate.first.get_number();
        int two_num = duplicate.second.get_number();
        if (threekind_check(three_num).first) new_value = threekind_value(three_num);
        else if (pair_check(two_num).first) new_value = pair_value(two_num);
        else new_value = highcard_value();
    } else if (type == 3){
        // two pair
        auto duplicate = get_combo_card<pair<Card,Card>>();
        int first_num = duplicate.first.get_number();
        int second_num = duplicate.second.get_number();
        if (pair_check(first_num).first && 
            pair_check(first_num).second.get_number() != second_num){
            new_value = pair_value(first_num);
        }
        else new_value = highcard_value();
    } else {
        new_value = highcard_value();
    }
    return new_value;
}

double Combo::highcard_value() const{
    auto copy_cards = get_cards();
    sort(copy_cards.begin(), copy_cards.end());
    return copy_cards[copy_cards.size()-1].get_value();
}

double Combo::pair_value(int duplicate) const{
    return HIGH_CARD + get_pair(duplicate).get_value() + 2;
}
double Combo::twopair_value() const{
    return PAIR + get_twopair().first.get_value() + get_twopair().second.get_value() + 2;
}
double Combo::threekind_value(int duplicate) const{
    return TWO_PAIR + get_threekind().get_value() + 3;
}
double Combo::straight_value() const{
    return THREE_KIND + get_straight().get_value() + 5;
}
double Combo::flush_value() const{
    return STRAIGHT + get_flush().get_value() + 5;
}
double Combo::fullhouse_value() const{
    return  FLUSH + get_fullhouse().first.get_value() + get_fullhouse().second.get_value() + 10;
}
double Combo::fourkind_value() const{
    return  FULL_HOUSE + get_fourkind().get_value() + 15;
}
double Combo::straightflush_value() const{ 
    return FOUR_KIND + get_straightflush().get_value() + 20;
}

void printCards(vector<Card> cards){
    for (int i = 0; i < (int)cards.size(); i++){
        cout << cards[i].get_number() << " ";
    }
    cout << endl;
}

pair<bool, Card> Combo::number_check(vector<Card> _cards, int req, int loop, int duplicate) const{
    int idx, n, new_idx;
    bool get;
    auto copy_cards = _cards;
    sort(copy_cards.begin(), copy_cards.end());
    // mengurut copy_cards dari yang terkecil ke terbesar
    idx = copy_cards.size() - 1;
    // idx adalah index dari kartu terbesar
    int number = copy_cards[idx].get_number();
    // number adalah nomor dari kartu terbesar  
    while (number == duplicate){
        // jika nomor kartu terbesar sama dengan duplicate
        idx--;
        number = copy_cards[idx].get_number();
    }
    for (int max = 0; max < loop; max ++){
        // loop sebanyak loop
        n = 1;
        get = false;
        for (int i = idx - 1 ; i >= 0 ; i--){
            if (copy_cards[i].get_number() != number || number == duplicate){
                // jika nomor kartu tidak sama dengan nomor kartu terbesar 
                // atau nomor kartu sama dengan duplicate
                if (!get) new_idx = i;
                // jika belum mendapatkan kartu yang sama dengan nomor kartu terbesar
                get = true;
                continue;
            } else n++;
            if (n == req) return make_pair(true, copy_cards[idx]);
            // jika nomor kartu sama dengan nomor kartu terbesar sebanyak req
        }
        idx = new_idx;
        // mengubah idx menjadi index kartu yang sama dengan nomor kartu terbesar
        number = copy_cards[idx].get_number();
    }
    return make_pair(false, Card(0, "none"));
}

pair<bool,Card> Combo::flush_check() const{
    auto copy_cards = cards;
    sort(copy_cards.begin(), copy_cards.end());
    // mengurut copy_cards dari yang terkecil ke terbesar
    int new_idx, n;
    bool get;
    int idx = copy_cards.size() - 1;
    // idx adalah index dari kartu terbesar
    string colour = copy_cards[idx].get_colour();
    for (int max = 0; max < 3; max ++){
        // loop sebanyak 3
        n = 1;
        get = false;
        for (int i = idx - 1 ; i >= 0 ; i--){
            // loop dari index kartu terbesar - 1 sampai 0
            if (copy_cards[i].get_colour() != colour){
                // jika warna kartu tidak sama dengan warna kartu terbesar
                if (!get) new_idx = i;
                get = true;
            } else n++;
            if (n == 5) return make_pair(true, copy_cards[idx]);
            // jika warna kartu sama dengan warna kartu terbesar sebanyak 5
        }    
        idx = new_idx;
        // mengubah idx menjadi index kartu yang sama dengan warna kartu terbesar
        colour = copy_cards[idx].get_colour();
    }
    return make_pair(false, Card(0, "none"));
}

pair<bool,Card> Combo::straight_check() const{
    auto copy_cards = cards;
    sort(copy_cards.begin(), copy_cards.end());
    // asumsi card tersusun dari kecil ke besar
    int idx;
    idx = copy_cards.size() - 1;
    int number = copy_cards[idx].get_number();
    for (int max = 0; max < 3; max++){
        int n = 1;
        for (int i = idx - 1 ; i >= 0 ; i--){
            if (copy_cards[i].get_number() == number){
                continue;
            }
            if (copy_cards[i].get_number() == number - 1){
                n++;
                number--;
            } else {
                idx = i;
                break;
            }
            if (n == 5) return make_pair(true, copy_cards[idx]);
        }
        number = copy_cards[idx].get_number();    
    }
    return make_pair(false, Card(0, "none"));
}

pair<bool,Card> Combo::fourkind_check() const{
    return number_check(cards, 4, 4, 0);
}

pair<bool,Card> Combo::threekind_check(int duplicate) const{
    return number_check(cards, 3, 5, duplicate);
}

pair<bool,Card> Combo::pair_check(int duplicate) const{
    return number_check(cards, 2, 6, duplicate);
}

pair<bool,Card> Combo::straightflush_check() const{
    auto p1 = straight_check();
    auto p2 = flush_check();
    if (p1.first && p2.first && p1.second.get_number() == p2.second.get_number()) {
        string colour = p2.second.get_colour();
        int number = p2.second.get_number();
        auto copy_cards = cards;
        sort(copy_cards.begin(), copy_cards.end());
        for (int i = copy_cards.size() - 1; i >= 0; i--){
            if (copy_cards[i].get_number() == number){
                continue;
            }
            if (copy_cards[i].get_number() == number - 1){
                if (copy_cards[i].get_colour() == colour)
                number--;
                else continue;
            } else {
                break;
            }
        }
        if (p1.second.get_number() - 4 >= number)
        return make_pair(true, p2.second);
    }
    return make_pair(false, Card(0, "none"));
}

pair<bool, pair<Card,Card>> Combo::twopair_check() const{
    auto p1 = pair_check();
    auto p2 = pair_check(p1.second.get_number());
    if (p1.first && p2.first) {
        if (p1.second.get_number() > p2.second.get_number()) return make_pair(true, make_pair(p1.second, p2.second));
        else return make_pair(true, make_pair(p2.second, p1.second));
    } else {
        return make_pair(false, make_pair(Card(0, "none"), Card(0, "none")));
    }
}

pair<bool, pair<Card,Card>> Combo::fullhouse_check() const{
    auto p1 = threekind_check();
    auto p2 = pair_check(p1.second.get_number());
    return make_pair(p1.first && p2.first, make_pair(p1.second, p2.second));
}



