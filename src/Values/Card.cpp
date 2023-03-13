#include "Card.hpp"
#include "../Exception/Exception.h"

Card::Card(int num, string col){
    if (num < 0 || num > 13) throw InvalidCardNumber();
    if (col != "hijau" && col != "biru" && col != "kuning" && col != "merah" && col != "none") 
    throw InvalidCardColour();
    number = num;
    colour = col;
}

Card::Card(const Card& c){
    number = c.number;
    colour = c.colour;
}

Card& Card::operator= (const Card& c){
    number = c.number;
    colour = c.colour;
    return *this;
}

Card::~Card(){}

int Card::get_number() const{
    return number;
}

string Card::get_colour() const{
    return colour;
}

double Card::colour_value(string col) const{
    double mult = 0;
    double val = 0.33;
    if(col == "hijau") mult = 0;
    if(col == "biru") mult = 1;
    if(col == "kuning") mult = 2;
    if(col == "merah") mult = 3;
    return val * mult;
}

double Card::number_value(int num) const{
    return num * 0.1;
}

double Card::get_value() const{
    return number_value(get_number()) + colour_value(get_colour());
}

bool operator== (const Card& c1, const Card& c2){
    return c1.colour == c2.colour && c1.number == c2.number;
}

bool operator< ( Card& c1,  Card& c2){
    if (c1.number == c2.number){
        return c1.colour_value(c1.colour) < c2.colour_value(c2.colour);
    } else {
        return c1.number < c2.number;
    }
}

bool operator> ( Card& c1,  Card& c2){
    if (c1.number == c2.number){
        return c1.colour_value(c1.colour) > c2.colour_value(c2.colour);
    } else {
        return c1.number > c2.number;
    }
}

ostream& operator<< (ostream& os, const Card& c){
    os << c.number << " " << c.colour;
    return os;
}