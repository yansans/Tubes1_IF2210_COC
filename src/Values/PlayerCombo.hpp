#ifndef PLAYERCOMBO_HPP
#define PLAYERCOMBO_HPP

#include "Combo.hpp"
#include "../Player/Player.hpp"
#include "../InventoryHolder/TableCards.hpp"

#include <iostream>
#include <vector>

using namespace std;

class PlayerCombo
{
private:
    static void debug_print(vector<Combo> combos, vector<Player *> players);

public:
    static Player *get_winner(vector<Player *> players, TableCards table);
};

#endif