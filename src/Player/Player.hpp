#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/PlayerCards.hpp"
#include "../Storage/DeckStorage.hpp"
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
    void takeCards();
    PlayerCards getCards();
    void setCards(PlayerCards);
    void reset();
    bool operator==(const Player &other);
    bool operator<(const Player &other);
    bool operator>(const Player &other);
};

#endif