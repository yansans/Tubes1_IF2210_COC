#ifndef __BLACKJACKCARD_HPP__
#define __BLACKJACKCARD_HPP__

#include "Values.hpp"

#include <string>
#include <iostream>
#include <map>

class BlackjackCard: public Values {
    private:
    std::string suit; /*club, heart, spade, diamond*/
    std::string value;

    public:
    static std::map<std::string, int> valuemap;
    double get_value() const;
    friend std::ostream& operator<<(std::ostream& out, BlackjackCard c);
};

#endif 