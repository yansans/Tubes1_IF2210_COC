#include "combo.hpp"
#include <string>

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

bool Combo::straight_check(){
    // asumsi card tersusun dari kecil ke besar
    int idx;
    idx = 0;
    int number = cards[idx].get_number();
    for (int max = 0; max < 3; max ++){
        int n = 1;
        for (int i = idx + 1; i < (int)cards.size() ; i++){
            if (cards[i].get_number() != number + 1){
                idx = i;
                break;
            } else {
                n++;
                number++;
            }
            if (n == 5) return true;
        }    
        number = cards[idx].get_number();
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

bool Combo::threekind_check(){
    int idx, n;
    idx = 0;
    int number = cards[idx].get_number();
    n = 1;
    for (int i = idx + 1; i < (int)cards.size() ; i++){
        if (cards[i].get_number() != number){
            continue;
        } else n++;
        if (n == 3) return true;
    } return false;
}

bool Combo::pair_check(){
    int idx, n;
    idx = 0;
    int number = cards[idx].get_number();
    n = 1;
    for (int i = idx + 1; i < (int)cards.size() ; i++){
        if (cards[i].get_number() != number){
            continue;
        } else n++;
        if (n == 2) return true;
    } return false;
}

bool Combo::straightflush_check(){
    return (straight_check() && flush_check());
}
