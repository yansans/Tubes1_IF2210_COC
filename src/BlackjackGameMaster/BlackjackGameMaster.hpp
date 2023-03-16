#ifndef __BLACKJACKGAMEMASTER_HPP__
#define __BLACKJACKGAMEMASTER_HPP__

#include <iostream>
#include <vector>

#include "../Player/BlackjackPlayer.hpp"
#include "../Player/BlackjackBot.hpp"
#include "../InventoryHolder/BlackjackPlayerCards.hpp"
#include "../InventoryHolder/BlackjackDeckCards.hpp"

class BlackjackGameMaster
{
protected:
    std::vector<BlackjackPlayer> player;
    std::vector<BlackjackBot> bot;
    std::vector<BlackjackParticipant *> participant;

    BlackjackDeckCards deck;

    static const int participantLimit = 8;

public:
    void playGame();
};

#endif