#ifndef __BLACKJACKGAMEMASTER_HPP__
#define __BLACKJACKGAMEMASTER_HPP__

#include <iostream>

#include "../Player/Player.hpp"
#include "../InventoryHolder/DeckCards.hpp"
#include "../InventoryHolder/BlackjackPlayerCards.hpp"


class BlackjackGameMaster {
    protected:
    Player player;
    Player bot;

    public:
    void playGame();
};

#endif