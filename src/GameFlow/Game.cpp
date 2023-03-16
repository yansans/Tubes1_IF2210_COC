#include "Game.hpp"

Game::Game()
{
    this->gameCount = 0;
}
int Game::getGame() const
{
    return this->gameCount + 1;
}
void Game::nextGame()
{
    this->gameCount++;
}