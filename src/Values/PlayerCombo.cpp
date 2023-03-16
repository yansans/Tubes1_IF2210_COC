#include "PlayerCombo.hpp"
#include <iostream>

using namespace std;

Player *PlayerCombo::get_winner(vector<Player *> players, TableCards table)
{
    vector<Combo> combos;
    vector<Card> cards;
    vector<int> highest_combos(players.size(), 0);
    vector<double> draw_value(players.size(), 0);
    Player *winner = players[0];

    for (int i = 0; i < players.size(); i++)
    {
        cards.push_back(players[i]->getCards().getLeftCard());
        cards.push_back(players[i]->getCards().getRightCard());
        for (int j = 0; j < table.getSize(); j++)
        {
            cards.push_back(table.getItem(j));
        }
        combos.push_back(Combo(cards));
        cards.clear();
    }

    // ! debug print
    // debug_print(combos, players);

    auto highest = 0;
    highest_combos.push_back(highest);
    for (int i = 1; i < combos.size(); i++)
    {
        if (combos[i] > combos[highest])
        {
            highest = i;
            highest_combos.clear();
            highest_combos.push_back(highest);
        }
        else if (combos[i] == combos[highest])
        {
            highest_combos.push_back(i);
        }
    }

    if (highest_combos.size() == 1)
    {
        winner = players[highest_combos[0]];
    }
    else
    {
        for (int i = 0; i < highest_combos.size(); i++)
        {
            draw_value.push_back(combos[highest_combos[i]].get_draw_value());
        }
        auto highest = 0;
        int count = 0;
        for (int i = 1; i < draw_value.size(); i++)
        {
            if (draw_value[i] > draw_value[highest])
            {
                highest = i;
            }
            else if (draw_value[i] == draw_value[highest])
            {
                count++;
            }
        }
        if (count != 0)
        {
            draw_value.clear();
            for (int i = 0; i < highest_combos.size(); i++)
            {
                draw_value.push_back(combos[highest_combos[i]].get_hands_value());
            }
            highest = 0;
            for (int i = 1; i < draw_value.size(); i++)
            {
                if (draw_value[i] > draw_value[highest])
                {
                    highest = i;
                }
            }
        }
        winner = players[highest_combos[highest]];
    }

    return winner;
}

void PlayerCombo::debug_print(vector<Combo> combos, vector<Player *> players)
{
    cout << endl;
    cout << "debug PlayerCombo" << endl;
    for (int i = 0; i < combos.size(); i++)
    {
        cout << "Player " << players[i]->getName() << " " << combos[i] << endl;
    }
    cout << endl;
}