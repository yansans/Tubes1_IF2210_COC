# include "AbilityHolder.cpp"
# include "../Ability/Ability.cpp"
# include "../Ability/Quadruple.cpp"
# include "../Ability/Quarter.cpp"
# include "../Ability/ReRoll.cpp"
# include "../Ability/Abilityless.cpp"
# include "../Player/Player.cpp"
# include "../InventoryHolder/PlayerCards.cpp"
# include "../InventoryHolder/InventoryHolder.cpp"
# include "../Values/Card.cpp"

int main() {
    Quadruple qdr;
    Quarter qtr;
    ReRoll rr;
    Abilityless a;

    Player dewana("Dewana");
    Player gustavus("Gustavus");
    Player haraka("Haraka");
    Player otang("Otang");

    vector<Player*> players;
    players.push_back(&dewana);
    players.push_back(&gustavus);
    players.push_back(&haraka);
    players.push_back(&otang);

    AbilityHolder ah(players);

    ah.addAbility(&dewana, &rr);
    ah.addAbility(&gustavus, &qdr);
    ah.addAbility(&haraka, &a);
    ah.addAbility(&otang, &qtr);

    cout << ah.checkPlayerHasAbility(&dewana, &rr) << endl;
    cout << ah.checkPlayerHasAbility(&gustavus, &a) << endl;

    cout << ah.checkAbilityOwner(&qtr)->getName() << endl;

    ah.removeAbility(&otang);

    return 0;
}