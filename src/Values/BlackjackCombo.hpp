#ifndef __BLACKJACKCOMBO_HPP__
#define __BLACKJACKCOMBO_HPP__

#include "BlackjackCard.hpp"
#include "../Util/util.hpp"
#include <vector>
#include <algorithm>
#include <numeric>


class BlackjackCombo: public Values {
    private:
    std::vector<BlackjackCard> cards;
    int ace_count() const;
    
    public:
    /**
     * @brief return value nearest to 21 (lower if possible)
     * 
     * @return value of BlackjackCombo
     */
    double get_value() const;
    bool isOut() const;
};

#endif