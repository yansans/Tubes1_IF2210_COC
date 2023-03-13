#include "Turn.hpp"

Turn::Turn(vector<Player> players)
{
    this->round = this->firstTurn = this->curTurn = 0;
    this->players = players;
}
Player Turn::currentTurn()
{
    return players[this->curTurn];
}
Player Turn::nextTurn()
{
    players[this->curTurn].setDone(true);
    this->curTurn = (this->curTurn + 1) % 7;
    if (players[this->curTurn].isDone())
        this->nextRound();
    return players[this->curTurn];
}
void Turn::reverse()
{
    players[this->curTurn].setDone(true);
    std::reverse(players.begin(), players.begin() + this->curTurn + 1);
    std::reverse(players.begin() + this->curTurn + 1, players.end());
    this->firstTurn = 0;
}
int Turn::getRound() const
{
    return this->round + 1;
}
void Turn::nextRound()
{
    this->round = (this->round + 1) % 6;
    this->firstTurn = this->curTurn = (this->firstTurn + 1) % 7;
    for (int i = 0; i < 7; i++)
    {
        players[i].setDone(false);
    }
}