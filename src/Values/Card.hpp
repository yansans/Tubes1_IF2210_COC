#ifndef CARD_HPP
#define CARD_HPP

#include "Values.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Card: public Values{
    private:
    int number;
    string colour;
    double val;

    double colour_value(string) const;
    double number_value(int) const;

    public:
    Card();
    Card(int, string);
    Card(const Card& c);
    Card& operator= (const Card& c);
    ~Card();

    int get_number() const;
    string get_colour() const;

    friend bool operator== (const Card& c1, const Card& c2);

    friend bool operator< (Card& c1,  Card& c2);

    friend bool operator> (Card& c1,  Card& c2);

    friend ostream& operator<< (ostream& os, const Card& c);

    double get_value() const override;
};
#endif