#ifndef __BLACKJACKCARD_HPP__
#define __BLACKJACKCARD_HPP__

#include "Values.hpp"

#include <string>
#include <iostream>
#include <map>
#include <vector>

class BlackjackCard : public Values
{
private:
    std::string suit; /*club, heart, spade, diamond*/
    std::string value;

public:
    BlackjackCard(std::string suit, std::string value);

    static std::map<std::string, int> valuemap;
    static std::vector<std::string> suitList;
    double get_value() const;
    friend std::ostream &operator<<(std::ostream &out, BlackjackCard c);
    bool operator==(const BlackjackCard &o);
};

#endif