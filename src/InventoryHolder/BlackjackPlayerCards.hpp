#ifndef __BLACKJACKPLAYERCARDS_HPP__
#define __BLACKJACKPLAYERCARDS_HPP__

#include "InventoryHolder.hpp"
#include "BlackjackDeckCards.hpp"
#include "../Values/BlackjackCard.hpp"
#include "../Values/BlackjackCombo.hpp"
#include <iostream>

class BlackjackPlayerCards: InventoryHolder<BlackjackCard> {
    public:
    BlackjackPlayerCards();
    // cctor dan operator= tidak diperlukan
    int value();
    bool isBust();
    bool isBlackjack();
    bool isLessThan(int x);
    bool canSplit();

    /**
     * @brief move top of deck to playercards;
     * 
     * @param deck 
     * @return BlackjackPlayerCards& 
     */
    BlackjackPlayerCards& operator<<(BlackjackDeckCards& deck);

    /**
     * @brief return card to deck
     * 
     * @param deck 
     * @param playercards 
     * @return BlackjackDeckCards& 
     */
    friend BlackjackDeckCards& operator<<(BlackjackDeckCards& deck, BlackjackPlayerCards& playercards);
    
    friend ostream& operator<<(ostream& out, BlackjackPlayerCards& playercards);
};

#endif