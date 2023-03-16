#include "Turn.hpp"

Turn::Turn() {}
Turn::Turn(vector<Player *> players) : Round()
{
    this->firstTurn = this->curTurn = 0;
    this->players = players;
    this->curPlayer = players[0];
}
Player *Turn::currentTurn()
{
    return this->curPlayer;
}
void Turn::nextTurn()
{
    players[this->curTurn]->setDone(true);
    this->curTurn = (this->curTurn + 1) % 7;
    if (players[this->curTurn]->isDone())
    {
        this->nextRound(players);
        Player* firstPlayer = players[0];
        players.erase(players.begin());
        players.push_back(firstPlayer);
        this->firstTurn = this->curTurn = 0;
        // this->firstTurn = this->curTurn = (this->firstTurn + 1) % 7;
    }
    this->curPlayer = players[this->curTurn];
}
void Turn::reverse()
{
    std::reverse(players.begin(), players.begin() + this->curTurn + 1);
    std::reverse(players.begin() + this->curTurn + 1, players.end());
    players[0]->setDone(true);
    this->curPlayer = players[0];
    this->firstTurn = 0;
}
vector<Player *> Turn::getPlayers()
{
    return this->players;
}
int Turn::getCurrentTurn()
{
    return this->curTurn;
}