#include "Turn.hpp"

Turn::Turn(vector<Player> players)
{
    this->round = this->first = this->cur = 0;
    this->players = players;
}
Player Turn::nextTurn()
{
    players[this->cur].setDone(true);
    this->cur = (this->cur + 1) % 7;
    if (players[this->cur].isDone())
        this->nextRound();
    return players[this->cur];
}
void Turn::reverse()
{
    std::reverse(players.begin(), players.begin() + this->cur + 1);
    std::reverse(players.begin() + this->cur + 1, players.end());
    this->first = 0;
}
int Turn::getRound() const
{
    return this->round + 1;
}
void Turn::nextRound()
{
    this->round = (this->round + 1) % 6;
    this->first = this->cur = (this->first + 1) % 7;
    for (int i = 0; i < 7; i++)
    {
        players[i].setDone(false);
    }
}