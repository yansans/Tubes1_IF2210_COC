#ifndef __BLACKJACKBOT_HPP__
#define __BLACKJACKBOT_HPP__

#include "BlackjackParticipant.hpp"

class BlackjackBot : public BlackjackParticipant
{
private:
    static int botCount;

public:
    BlackjackBot();

    void playTurn(BlackjackDeckCards &deck);
    void printInfo(int hideCnt = 1);
};

#endif