#include "BlackjackBot.hpp"

int BlackjackBot::botCount = 0;

BlackjackBot::BlackjackBot()
{
    botCount++;
    this->name = "Bot " + to_string(botCount);
}

void BlackjackBot::playTurn(BlackjackDeckCards &deck)
{
    std::cout << "=======================" << std::endl
              << name << "\'s turn" << std::endl
              << "=======================" << std::endl;
    while (cards.value() < 17) {
        std::cout << "Bot mengambil kartu " << deck.getTop() << std::endl;
        this->cards << deck;
    }
    std::cout << "Giliran Bot selesai" << std::endl << std::endl;
}

void BlackjackBot::printInfo(int hideCnt)
{
    std::cout << "Bot " << name << std::endl;
    this->cards.outputHide(hideCnt);
}
