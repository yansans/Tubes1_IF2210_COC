#include "Game.hpp"

Game::Game()
{
    this->gameCount = 0;
}
int Game::getGame() const
{
    return this->gameCount + 1;
}
void Game::nextGame(vector<Player *> &players)
{
    this->gameCount++;
    for (int i = 0; i < 7; i++)
    {
        players[i]->reset();
    }
}