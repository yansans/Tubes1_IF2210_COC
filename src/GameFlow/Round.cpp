#include "Round.hpp"

Round::Round() : Game()
{
    this->roundCount = 0;
}
int Round::getRound() const
{
    return this->roundCount + 1;
}
void Round::nextRound(vector<Player *> &players)
{
    this->roundCount = (this->roundCount + 1) % 6;
    for (int i = 0; i < 7; i++)
    {
        players[i]->setDone(false);
    }
    
    if (this->roundCount == 0)
        this->nextGame();
}