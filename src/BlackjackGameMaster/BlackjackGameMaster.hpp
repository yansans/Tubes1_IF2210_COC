#ifndef __BLACKJACKGAMEMASTER_HPP__
#define __BLACKJACKGAMEMASTER_HPP__

#include <iostream>

#include "../Player/BlackjackPlayer.hpp"
#include "../InventoryHolder/BlackjackPlayerCards.hpp"
#include "../InventoryHolder/BlackjackDeckCards.hpp"


class BlackjackGameMaster {
    protected:
    BlackjackPlayer player;
    BlackjackPlayer bot;
    BlackjackDeckCards deck;

    public:
    void playGame();
};

#endif