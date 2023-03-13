#include "Combo.hpp"
#include <string>
#include <algorithm>
#include <utility>

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

bool Combo::is_straightflush() const{
    return straightflush_check().first;
}

bool Combo::is_fourkind() const{
    return fourkind_check().first;
}

bool Combo::is_fullhouse() const{
    return fullhouse_check().first;
}

bool Combo::is_flush() const{
    return flush_check().first;
}

bool Combo::is_straight() const{
    return straight_check().first;
}

bool Combo::is_threekind(int duplicate) const{
    return threekind_check(duplicate).first;
}

bool Combo::is_twopair() const{
    return twopair_check().first;
}

bool Combo::is_pair(int duplicate) const{
    return pair_check(duplicate).first;
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

double Combo::get_value() const{
    double value = 0;
    if (is_straightflush()){
        value = straightflush_value();
    }
    else if (is_fourkind()){
        value = fourkind_value();
    }
    else if (is_fullhouse()){
        value = fullhouse_value();
    }
    else if (is_flush()){
        value = flush_value();
    }
    else if (is_straight()){
        value = straight_value();
    }
    else if (is_threekind()){
        value = threekind_value();
    }
    else if (is_twopair()){
        value = twopair_value();
    }
    else if (is_pair()){
        value = pair_value();
    }
    else{
        auto copy_cards = cards;
        sort(copy_cards.begin(), copy_cards.end());
        value = copy_cards[copy_cards.size() - 1].get_value();
    }
    
    return value;
}

double Combo::get_draw_value() const{
    double value = 0;
    if (is_threekind()){
        value = threekind_value();
    }
    else if (is_twopair()){
        value = twopair_value();
    }
    else if (is_pair()){
        value = pair_value();
    }
    else{
        auto copy_cards = cards;
        sort(copy_cards.begin(), copy_cards.end());
        value = copy_cards[copy_cards.size() - 1].get_value();
    }
    
    return value;
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
    idx = copy_cards.size() - 1;
    int number = copy_cards[idx].get_number();
    while (number == duplicate){
        idx--;
        number = copy_cards[idx].get_number();
    }
    for (int max = 0; max < loop; max ++){
        n = 1;
        get = false;
        for (int i = idx - 1 ; i >= 0 ; i--){
            if (copy_cards[i].get_number() != number || number == duplicate){
                if (!get) new_idx = i;
                get = true;
                continue;
            } else n++;
            if (n == req) return make_pair(true, copy_cards[idx]);
        }
        idx = new_idx;
        number = copy_cards[idx].get_number();
    }
    return make_pair(false, Card(0, "none"));
}

pair<bool,Card> Combo::flush_check() const{
    auto copy_cards = cards;
    sort(copy_cards.begin(), copy_cards.end());
    int new_idx, n;
    bool get;
    int idx = copy_cards.size() - 1;
    string colour = copy_cards[idx].get_colour();
    for (int max = 0; max < 3; max ++){
        n = 1;
        get = false;
        for (int i = idx - 1 ; i >= 0 ; i--){
            if (copy_cards[i].get_colour() != colour){
                if (!get) new_idx = i;
                get = true;
            } else n++;
            if (n == 5) return make_pair(true, copy_cards[idx]);
        }    
        idx = new_idx;
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
    if (p1.first && p2.first && p1.second == p2.second) return make_pair(true, p1.second);
    else return make_pair(false, Card(0, "none"));
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



