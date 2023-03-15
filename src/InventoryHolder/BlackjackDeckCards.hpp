#ifndef __BLACKJACKDECKCARDS_HPP__
#define __BLACKJACKDECKCARDS_HPP__

#include "InventoryHolder.hpp"
#include "../Values/BlackjackCard.hpp"
#include "BlackjackPlayerCards.hpp"
#include "../Exception/Exception.h"
#include <algorithm>
#include <string>
#include <vector>
#include <map>

class BlackjackDeckCards: public InventoryHolder<BlackjackCard> {
    public:
    /**
     * @brief Construct a random Blackjack Deck Cards 
     * 
     */
    BlackjackDeckCards();

    /**
     * @brief Get the Top card in deck.
     * 
     * @return BlackjackCard 
     */
    BlackjackCard getTop();
    /**
     * @brief Delete top card in deck
     * 
     */
    void pop();
    
    void shuffle();
    
};

#endif