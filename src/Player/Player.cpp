#include "Player.hpp"

Player::Player(string name)
{
    this->name = name;
    this->point = 0;
    this->done = false;
}
string Player::getName() const
{
    return this->name;
}
void Player::setName(string name)
{
    this->name = name;
}
long long Player::getPoint() const
{
    return this->point;
}
void Player::addPoint(long long point)
{
    this->point += point;
}
bool Player::isDone() const
{
    return this->done;
}
void Player::setDone(bool info)
{
    this->done = info;
}
void Player::takeCards(DeckCards &deckCards)
{
    for (int i = 0; i < 2; i++)
    {
        this->cards += deckCards.getItem(0);
        deckCards -= deckCards.getItem(0);
    }
}
PlayerCards Player::getCards()
{
    return this->cards;
}
void Player::reset(DeckCards &deckCards)
{
    this->setDone(false);
    for (int i = 0; i < 2; i++)
    {
        deckCards += this->cards.getItem(0);
        this->cards -= this->cards.getItem(0);
    }
}
bool Player::operator==(const Player &other)
{
    return this->getPoint() == other.getPoint();
}
bool Player::operator<(const Player &other)
{
    return this->getPoint() < other.getPoint();
}
bool Player::operator>(const Player &other)
{
    return this->getPoint() > other.getPoint();
}