#include "Combo.hpp"
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

Combo::Combo(vector<Card> _cards){
    cards = _cards;
}

Combo::~Combo(){
    cards.clear();
}

vector<Card> Combo::get_cards(){
    return cards;
}

bool Combo::flush_check(){
    int idx, new_idx, n;
    bool get;
    idx = 0;
    string colour = cards[idx].get_colour();
    for (int max = 0; max < 3; max ++){
        n = 1;
        get = false;
        for (int i = idx + 1; i < (int)cards.size() ; i++){
            if (cards[i].get_colour() != colour){
                if (!get) new_idx = i;
                get = true;
            } else n++;
            if (n == 5) return true;
        }    
        idx = new_idx;
        colour = cards[idx].get_colour();
    }
    return false;
}

void print(vector<Card> cards){
    for (int i = 0; i < (int)cards.size(); i++){
        cout << cards[i].get_number() << " ";
    }
    cout << endl;
}

bool Combo::straight_check(){
    auto copy_cards = cards;
    sort(copy_cards.begin(), copy_cards.end());
    // print(copy_cards);
    // print(cards);
    // asumsi card tersusun dari kecil ke besar
    int idx;
    idx = 0;
    int number = copy_cards[idx].get_number();

    for (int max = 0; max < 3; max++){
        int n = 1;
        for (int i = idx + 1; i < (int)copy_cards.size() ; i++){
            if (copy_cards[i].get_number() == number){
                continue;
            }
            if (copy_cards[i].get_number() == number + 1){
                n++;
                number++;
            } else {
                idx = i;
                break;
            }
            if (n == 5) return true;
        }
        number = copy_cards[idx].get_number();    
    }
    return false;
}

bool Combo::fourkind_check(){
    int idx, n;
    idx = 0;
    int number = cards[idx].get_number();
    n = 1;
    for (int i = idx + 1; i < (int)cards.size() ; i++){
        if (cards[i].get_number() != number){
            continue;
        } else n++;
        if (n == 4) return true;
    } return false;
}

pair<bool,int> Combo::threekind_check(int duplicate = 0){
    int idx, n, new_idx;
    bool get;
    idx = 0;
    int number = cards[idx].get_number();
    n = 1;
    for (int max = 0 ; max < 2 ; max ++){
        for(int i = idx + 1; i < (int)cards.size(); i++){
            if (cards[i].get_number() != number && duplicate == number){
                if (!get) new_idx = i;
                get = true;
                continue;
            } else n++;
            if (n == 3) return pair<bool,int>(true, number);
        } 
        idx = new_idx;
        number = cards[idx].get_number();
    }
    return pair<bool, int>(false, 0);
}

pair<bool,int> Combo::pair_check(int duplicate = 0){
    int idx, n, new_idx;
    bool get;
    idx = 0;
    int number = cards[idx].get_number();
    while (number == duplicate && idx < (int)cards.size() - 1){
        idx++;
        number = cards[idx].get_number();
    }
    n = 1;
    for (int max = 0; max < 3; max ++){
        for (int i = idx + 1; i < (int)cards.size() ; i++){
            if (cards[i].get_number() != number && duplicate == number){
                if (!get) new_idx = i;
                get = true;
                continue;
            } else n++;
            if (n == 2) return pair<bool,int>(true, number);
        }
        idx = new_idx;
        number = cards[idx].get_number();
    }
    return pair<bool, int>(false, 0);
}

bool Combo::straightflush_check(){
    return (straight_check() && flush_check());
}

bool Combo::twopair_check(){
    pair <bool, int> p1, p2;
    p1 = pair_check();
    // cout << p1.second << endl;
    p2 = pair_check(p1.second);
    // cout << p2.second << endl;
    return (p1.first && p2.first);
}

bool Combo::fullhouse_check(){
    pair <bool, int> p1, p2;
    p1 = threekind_check();
    // cout << p1.second << endl;
    p2 = pair_check(p1.second);
    // cout << p2.second << endl;
    return (p1.first && p2.first);
}

double Combo::get_value(){
    bool val; 
    if (straightflush_check()) return 9;
    if (fourkind_check()) return 8;
    if (fullhouse_check()) return 7;
    if (flush_check()) return 6;
    if (straight_check()) return 5;
    val = threekind_check().first;
    if (val) return 4;
    val = twopair_check();
    if (val) return 3;
    val = pair_check().first;
    if (val) return 2;
    return 1;
}

