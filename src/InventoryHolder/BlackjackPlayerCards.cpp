#include "BlackjackPlayerCards.hpp"


BlackjackPlayerCards::BlackjackPlayerCards() : InventoryHolder<BlackjackCard>(21) {}

int BlackjackPlayerCards::value()
{
    BlackjackCombo combo(this->items);
    return combo.get_value();
}

bool BlackjackPlayerCards::isBust()
{
    return value() > 21;
}

bool BlackjackPlayerCards::isBlackjack()
{
    return value() == 21;
}

bool BlackjackPlayerCards::isLessThan(int x)
{
    return value() < x;
}

bool BlackjackPlayerCards::canSplit()
{
    return (this->items.size() == 2) && (this->items[0].get_value() == this->items[1].get_value());
}

BlackjackDeckCards& operator<<(BlackjackDeckCards& deck, BlackjackPlayerCards& playercards)
{
    BlackjackCard b = playercards.getItem(playercards.getSize()-1);
    deck.insertItem(b);
    playercards.removeItem(b);
    deck.shuffle();

    return deck;
}

BlackjackPlayerCards& BlackjackPlayerCards::operator<<(BlackjackDeckCards& deck)
{
    this->items.push_back(deck.getTop());
    deck.pop();
    return *this;
}

std::ostream& operator<<(std::ostream& out, BlackjackPlayerCards& playercards)
{
    std::cout << "Kartu: ";
    for (int i = 0; i < playercards.items.size() - 1; i++) {
        std::cout << playercards.items[i] << " && ";
    }
    std::cout << playercards.items.back();
    return out;
}