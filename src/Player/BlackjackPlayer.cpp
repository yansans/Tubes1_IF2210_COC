#include "BlackjackPlayer.hpp"
#include "../Exception/Exception.h"
#include <set>
#include <functional>

BlackjackPlayer::BlackjackPlayer() {}

void BlackjackPlayer::getInitialCards(BlackjackDeckCards &deck)
{
    this->cards << deck << deck;
}

void BlackjackPlayer::playTurn(BlackjackDeckCards &deck)
{
    auto printCommands = []() {
        std::cout << "Commands:" << std::endl
                  << "- hit (ambil satu kartu)" << std::endl
                  << "- stand (stop mengambil kartu)" << std::endl;
    };
    auto printSplitCommand = []() {
        std::cout << "- split (buang dan ambil satu kartu; ditawarkan jika kedua kartu di tangan bernilai sama)" << std::endl;
    };

    std::cout << "=======================" << std::endl
              << name << "\'s turn" << std::endl
              << "=======================" << std::endl;

    std::string playerCommand;
    while(true) {
        try {
            std::cout << cards << std::endl;
            printCommands();
            if (this->cards.canSplit()) {
                printSplitCommand();
            }
            std::cout << "Perintah anda: ";
            std::cin >> playerCommand;
            if (playerCommand == "hit") {
                std::cout << "Anda mendapat kartu " << deck.getTop() << std::endl;
                this->cards << deck;
            }
            else if (playerCommand == "stand") {
                std::cout << "Giliran dilanjutkan" << std::endl;
                break;
            }
            else if (playerCommand == "split") {
                if (this->cards.canSplit()) {
                    deck << this->cards;
                    std::cout << "Anda melakukan split dan mendapat kartu " << deck.getTop() << std::endl;
                    this->cards << deck;
                }
                else throw InvalidCommand();
            }
            else throw InvalidCommand();
        }
        catch (InvalidCommand e) {
            std::cout << "Invalid command!" << std::endl;
        }
        catch (exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void BlackjackPlayer::playBot(BlackjackDeckCards &deck)
{
    while (cards.value() < 17) {
        std::cout << "Bot mengambil kartu " << deck.getTop() << std::endl;
        this->cards << deck;
    }
    std::cout << "Giliran Bot selesai" << std::endl;
}

void BlackjackPlayer::askForName()
{
    std::cout << "Name: ";
    std::cin >> this->name;
}

