#include "../Player/Player.hpp"
#include "../Exception/Exception.h"
#include "../InventoryHolder/DeckCards.hpp"
#include "../InventoryHolder/TableCards.hpp"
#include "../Command/CommandList.hpp"
#include "../AbilityHolder/AbilityHolder.hpp"
#include "../GameFlow/Turn.hpp"
#include "../Values/PlayerCombo.hpp"
#include "../Util/util.hpp"
#include "../Storage/DeckStorage.hpp"

class KerajaanPermen
{
private:
    vector<Player *> players;
    TableCards tableCards;
    const long long winningScore = 1LL << 32;
    long long rewardPoint = 64;
    AbilityHolder abilityHolder;
    Turn turn;

    void inputPlayers();
    bool checkFileExist(string fileName);
    string getFileName();
    DeckCards inputDeckCard();
    void inputDeckCardLoop();
    long long highestScore();
    void displayEndGame();
    void playerOptionInput(Player &player);
    vector<Ability *> generateRandomAbility();
    void playerMenu(Player &player);
    void drawCards(int round);
    void checkWinner();
    void gameLoop();

public:
    ~KerajaanPermen();
    void playGame();
};