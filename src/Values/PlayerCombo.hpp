#include "Combo.hpp"
#include "../Player/Player.hpp"
#include "../InventoryHolder/TableCards.hpp"

#include <iostream>
#include <vector>

using namespace std;

class PlayerCombo{

    public:
    static Player* get_winner(vector<Player*> players, TableCards table);

};