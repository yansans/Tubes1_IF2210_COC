#ifndef COMBO_HPP
#define COMBO_HPP

#include "Card.hpp"
#include <vector>
#include <utility>

using namespace std;

class Combo: public Values{
    private:
    vector<Card> cards;    
    pair<bool, Card> number_check(vector<Card>, int req, int loop, int duplicate) const;

    pair<bool,Card> straightflush_check() const;
    pair<bool,Card> fourkind_check() const;
    pair<bool, pair<Card,Card>> fullhouse_check() const;
    pair<bool,Card> flush_check() const;
    pair<bool,Card> straight_check() const;
    pair<bool,Card> threekind_check(int duplicate = 0) const;
    pair<bool, pair<Card,Card>> twopair_check() const;
    pair<bool,Card> pair_check(int duplicate = 0) const;

    Card get_straightflush() const;
    Card get_fourkind() const;
    pair<Card,Card> get_fullhouse() const;
    Card get_flush() const;
    Card get_straight() const;
    Card get_threekind(int duplicate = 0) const;
    pair<Card,Card> get_twopair() const;
    Card get_pair(int duplicate = 0) const;
    Card get_highcard() const;

    const double HIGH_CARD = 1.39;
    const double PAIR = (HIGH_CARD * 2) + 2;
    const double TWO_PAIR = PAIR + (HIGH_CARD * 2) + 2;
    const double THREE_KIND = TWO_PAIR + (HIGH_CARD) + 3;
    const double STRAIGHT = THREE_KIND + HIGH_CARD + 5;
    const double FLUSH = STRAIGHT + HIGH_CARD + 5;
    const double FULL_HOUSE = FLUSH + (HIGH_CARD * 2) + (HIGH_CARD) + 10;
    const double FOUR_KIND = FULL_HOUSE + HIGH_CARD + 15;
    const double STRAIGHT_FLUSH = FOUR_KIND + HIGH_CARD + 20;

    double highcard_value() const;
    double pair_value(int duplicate = 0) const;
    double twopair_value()const;
    double threekind_value(int duplicate = 0)const;
    double straight_value()const;
    double flush_value()const;
    double fullhouse_value()const;
    double fourkind_value()const;
    double straightflush_value()const;

    public:

    Combo(const vector<Card>);

    Combo& operator=(const Combo &other);

    ~Combo();

    vector<Card> get_cards() const;

    int get_combo_type() const;

    template<typename T>
    T get_combo_card() const;

    bool operator<(const Combo &other) const;
    bool operator>(const Combo &other) const;
    bool operator==(const Combo &other) const;

    double get_value() const override;

    double get_draw_value() const;

    void print_type() const;

    friend void printCards(vector<Card> cards);
}; 

void printCards(vector<Card> cards);

#endif