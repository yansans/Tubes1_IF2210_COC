#include "BlackjackCombo.hpp"

int BlackjackCombo::ace_count() const
{
    return std::count_if(cards.begin(), cards.end(), [](BlackjackCard c) { return c.get_value() == 11; });
}

BlackjackCombo::BlackjackCombo(const std::vector<BlackjackCard> &inven)
{
    cards = inven;
}

double BlackjackCombo::get_value() const
{
    std::function<int(BlackjackCard)> lambda = [](BlackjackCard c){ return (int)(c.get_value()); };
    int maxsum = sumElement(cards, lambda);
    int acecnt = ace_count();
    while(maxsum > 21 && acecnt) {
        maxsum -= 10;
        acecnt--;
    }
    return maxsum;
}

