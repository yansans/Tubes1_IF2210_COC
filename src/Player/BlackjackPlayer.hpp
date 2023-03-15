#ifndef __BLACKJACKPLAYER_HPP__
#define __BLACKJACKPLAYER_HPP__

#include <string>
#include "../InventoryHolder/BlackjackPlayerCards.hpp"

class BlackjackPlayer {
    private:
    std::string name;
    BlackjackPlayerCards cards;

    public:
    BlackjackPlayer();
    void getInitialCards(BlackjackDeckCards &deck);
    void playTurn(BlackjackDeckCards &deck);
    void playBot(BlackjackDeckCards &deck);
    void askForName();
    void setName(std::string name);
    int score();

    void printInfo();
};

#endif