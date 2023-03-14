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
    {"A", 11}
};

double BlackjackCard::get_value()
{
    return (double)valuemap[value];
}
