#include "PlayerCombo.hpp"

Player* PlayerCombo::get_winner(vector<Player*> players, TableCards table){
    vector<Combo> combos;
    vector<Card> cards;
    vector<int> highest_combos;
    vector<double> draw_value;
    Player* winner = nullptr;

    for (int i = 0; i < players.size(); i++){
        cards.push_back(players[i]->getCards().getLeftCard());
        cards.push_back(players[i]->getCards().getRightCard());
        // ! check getter TableCards
        for (int j = 0; j < table.getSize(); j++){
            cards.push_back(table.getItem(j));
        }
        combos.push_back(Combo(cards));
        cards.clear();
    }

    auto highest = 0;
    highest_combos.push_back(highest);
    for (int i = 1; i < combos.size(); i++){
        if (combos[i] > combos[highest]){
            highest = i;
            highest_combos.clear();
            highest_combos.push_back(highest);
        } else if (combos[i] == combos[highest]){
            highest_combos.push_back(i);
        }
    }

    if (highest_combos.size() == 1){                
        winner = players[highest_combos[0]];
    } else {
        for (int i = 0; i < highest_combos.size(); i++){
            draw_value.push_back(combos[highest_combos[i]].get_draw_value());
        }
        auto highest = 0;
        for (int i = 1; i < draw_value.size(); i++){
            if (draw_value[i] > draw_value[highest]){
                highest = i;
            }
        }
        winner = players[highest_combos[highest]];
    }


    return winner;
}
