#include "BlackjackCard.hpp"

std::map<std::string, int> BlackjackCard::valuemap = {
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"J", 10},
    {"Q", 10},
    {"K", 10},
    {"A", 11}};

std::vector<std::string> BlackjackCard::suitList = {
    "club",
    "heart",
    "spade",
    "diamond"};

double BlackjackCard::get_value() const
{
    return (double)(valuemap[value]);
}

bool BlackjackCard::operator==(const BlackjackCard &o)
{
    return this->suit == o.suit && this->value == o.value;
}

std::ostream &operator<<(std::ostream &out, BlackjackCard c)
{
    out << c.value << " " << c.suit;
    return out;
}

BlackjackCard::BlackjackCard(std::string suit, std::string value) : suit(suit), value(value) {}
