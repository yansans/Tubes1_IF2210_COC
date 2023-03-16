#ifndef __BLACKJACKPLAYER_HPP__
#define __BLACKJACKPLAYER_HPP__

#include "BlackjackParticipant.hpp"

class BlackjackPlayer : public BlackjackParticipant
{
private:
    static int namedPlayerCount;

public:
    void askForName();
    void playTurn(BlackjackDeckCards &deck);

    void printInfo(int hideCnt = 0);
};

#endif