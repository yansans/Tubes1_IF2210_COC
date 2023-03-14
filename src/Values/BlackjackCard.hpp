#ifndef __BLACKJACKCARD_HPP__
#define __BLACKJACKCARD_HPP__

#include "Values.hpp"

#include <string>
#include <iostream>
#include <map>

class BlackjackCard: Values {
    private:
    std::string suit; /*club, heart, spade, diamond*/
    std::string value;

    public:
    static const std::map<string, int> valuemap;
    double get_value();
}

#endif 