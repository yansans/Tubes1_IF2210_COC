#include "BlackjackDeckCards.hpp"
#include <random>
#include <chrono>

BlackjackDeckCards::BlackjackDeckCards() : InventoryHolder<BlackjackCard>(52)
{
    for (std::string suit: BlackjackCard::suitList) {
        for (std::pair<std::string, int> val: BlackjackCard::valuemap) {
            this->items.push_back(BlackjackCard(suit, val.first));
        }
    }

    shuffle();
}

BlackjackCard BlackjackDeckCards::getTop() {
    if (items.empty()) throw EmptyContainerException();
    return getItem(items.size()-1);
}

void BlackjackDeckCards::pop() {
    if (items.empty()) throw EmptyContainerException();
    items.pop_back();
}

void BlackjackDeckCards::shuffle()
{
    std::shuffle(this->items.begin(), this->items.end(), std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count()));
}

