#ifndef CARD_HPP
#define CARD_HPP

#include "values.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Card: public Values{
    private:
    int number;
    string colour;
    double val;

    double colour_value(string);
    double number_value(int);

    public:
    Card(int, string);
    ~Card();

    int get_number();
    string get_colour();

    friend bool operator== (const Card& c1, const Card& c2){
        return c1.colour == c2.colour && c1.number == c2.number;
    }

    double get_value() override;
};

class Combo: public Values{
    private:
    vector<Card> cards;


    public:
    Combo(vector<Card> _cards){
        cards = _cards;
    }

    ~Combo(){}

    bool flush_check(){
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

    bool straight_check(){
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

    bool fourkind_check(){
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

    bool threekind_check(){
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

    bool pair_check(){
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


    bool straightflush_check(){
        return (straight_check() && flush_check());
    }
    // check flush dan straight

    bool twopair_check();
    // check 2 2 card same number

    bool fullhouse_check();
    // check three kind and pair

    vector<Card> get_cards(){
        return cards;
    }

    double get_value() override{
        return 0;
    }
}; 

#endif