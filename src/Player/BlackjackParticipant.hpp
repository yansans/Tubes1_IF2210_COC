#ifndef __BLACKJACKPARTICIPANT_HPP__
#define __BLACKJACKPARTICIPANT_HPP__

#include <string>
#include "../InventoryHolder/BlackjackPlayerCards.hpp"

class BlackjackParticipant
{
protected:
    std::string name;
    BlackjackPlayerCards cards;

public:
    BlackjackParticipant();
    void getInitialCards(BlackjackDeckCards &deck);
    virtual void playTurn(BlackjackDeckCards &deck) = 0;
    void askForName(); // child
    void setName(std::string name);
    int score();
    bool operator<(BlackjackParticipant &o);
    /**
     * @brief output info with some card hidden.
     *
     *
     * @param hideCnt = 0 to reveal all, no param default
     */
    virtual void printInfo(int hideCnt = 0) = 0;
};

#endif