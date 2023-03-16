#include "BlackjackGameMaster.hpp"
#include <iostream>
#include <functional>

void BlackjackGameMaster::playGame()
{
    auto printScore = [](BlackjackPlayer &player) {
        std::cout << "Skor: " << player.score() << (player.score() == -1 ? "(lebih dari 21)": "") << std::endl;
    };
    std::cout << "Permainan blackjack dimulai!" << std::endl << std::endl;

    player.askForName();
    bot.setName("Bot 1");
    
    player.getInitialCards(deck);
    bot.getInitialCards(deck);

    std::cout << "Keadaan setelah pengambilan kartu awal" << std::endl;
    player.printInfo();
    std::cout << std::endl;
    bot.printInfoDealer();
    std::cout << std::endl;

    player.playTurn(deck);
    bot.playBot(deck);

    std::cout << "Status akhir:" << std::endl;
    player.printInfo();
    printScore(player);
    std::cout << std::endl;

    bot.printInfoDealer(0);
    printScore(bot);
    std::cout << std::endl;
    std::cout << std::endl;

    if (player.score() == bot.score()) {
        std::cout << "Seri" << std::endl;
    }
    else if (player.score() > bot.score()) {
        std::cout << "Anda Menang!!" << std::endl;
    }
    else {
        std::cout << "Bot Menang" << std::endl;
    }
}
