#ifndef COMBO_HPP
#define COMBO_HPP

#include "Card.hpp"
#include <vector>

using namespace std;

class Combo: public Values{
    private:
    vector<Card> cards;    

    public:
    bool straightflush_check();
    // check flush dan straight
    bool fourkind_check();
    // check 4 card same number
    bool fullhouse_check();
    // check three kind and pair
    bool flush_check();
    // check 5 card same colour
    bool straight_check();
    // check 5 card in order
    pair<bool,int> threekind_check(int duplicate);
    // check 3 card same number
    bool twopair_check();
    // check 2 2 card same number
    pair<bool,int> pair_check(int duplicate);
    // check 2 card same number

    Combo(const vector<Card>);

    ~Combo();

    vector<Card> get_cards();

    double get_value() override;

    friend void print(vector<Card> cards);
}; 

#endif