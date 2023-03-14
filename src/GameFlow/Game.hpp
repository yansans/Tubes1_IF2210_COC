#ifndef GAME_HPP
#define GAME_HPP

#include "../Player/Player.hpp"
using namespace std;

class Game
{
private:
    int gameCount;

public:
    Game();
    int getGame() const;
    void nextGame(vector<Player *> &players);
};

#endif