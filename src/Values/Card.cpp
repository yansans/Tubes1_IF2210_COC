#include "card.hpp"

Card::Card(int num, string col){
    // tambah exception
    number = num;
    colour = col;
}

Card::~Card(){}

int Card::get_number(){
    return number;
}

string Card::get_colour(){
    return colour;
}

double Card::colour_value(string col){
    double mult = 0;
    double val = 0.33;
    // tambah exception
    if(col == "biru") mult = 1;
    if(col == "kuning") mult = 2;
    if(col == "merah") mult = 3;
    return val * mult;
}

double Card::number_value(int num){
    return num * 0.1;
}

double Card::get_value(){
    return number_value(get_number()) + colour_value(get_colour());
}

bool operator== (const Card& c1, const Card& c2){
    return c1.colour == c2.colour && c1.number == c2.number;
}

bool operator< ( Card& c1,  Card& c2){
    double c1_colour = c1.colour_value(c1.colour);
    double c2_colour = c2.colour_value(c2.colour);
    if (c1.number == c2.number){
        return c1_colour < c2_colour;
    } else {
        return c1.number < c2.number;
    }
}

ostream& operator<< (ostream& os, const Card& c){
    os << c.number << " " << c.colour;
    return os;
}