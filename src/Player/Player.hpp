#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/PlayerCards.hpp"
#include "../InventoryHolder/DeckCards.hpp"
using namespace std;

class Player
{
private:
    string name;
    long long point;
    PlayerCards cards;
    bool done;

public:
    Player(string name);
    string getName() const;
    void setName(string name);
    long long getPoint() const;
    void addPoint(long long point);
    bool isDone() const;
    void setDone(bool info);
    void takeCards(DeckCards &deckCards);
    PlayerCards getCards();
    void setCards(PlayerCards);
    void reset(DeckCards & deckCards);
    bool operator==(const Player &other);
    bool operator<(const Player &other);
    bool operator>(const Player &other);
};

#endif