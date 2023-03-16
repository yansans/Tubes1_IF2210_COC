/* Bonus: permainan kartu blackjack
 * Catatan: aturan permainan berbeda dari blackjack biasa, untuk menghilangkan
 *          elemen perjudian.
 *          Jika ada pemain dengan nilai sama pada akhir permainan,
 *          permainan berakhir seri
 */
#include "BlackjackGameMaster/BlackjackGameMaster.hpp"
#include "InventoryHolder/DeckCards.hpp"

DeckCards Deck;
int main()
{
    BlackjackGameMaster game;
    game.playGame();
    return 0;
}