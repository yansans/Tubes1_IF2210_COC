#include "BlackjackGameMaster.hpp"
#include "../Exception/Exception.h"
#include "../Util/util.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <chrono>

void BlackjackGameMaster::playGame()
{
    auto printScore = [](BlackjackParticipant &player) {
        std::cout << "Skor: " << player.score() << (player.score() == -1 ? "(lebih dari 21)": "") << std::endl;
    };
    auto pause = []() {
        std::cout << "PRESS ENTER TO CONTINUE...";
        std::string tmp;
        std::getline(std::cin, tmp);
    };
    std::cout << "Permainan blackjack dimulai!" << std::endl << std::endl;
    int playerCnt, botCnt;

    while(true) {
        try {
            std::string tmpstr;
            std::cout << "Jumlah pemain = ";
            std::getline(std::cin, tmpstr);
            playerCnt = std::stoi(tmpstr);
            if (playerCnt > participantLimit) 
                throw ParticipantCountAboveLimit();

            std::cout << "Jumlah bot = ";
            std::getline(std::cin, tmpstr);
            botCnt = std::stoi(tmpstr);
            if (playerCnt + botCnt > participantLimit) 
                throw ParticipantCountAboveLimit();
            
            player.resize(playerCnt);
            bot.resize(botCnt); 
            
            std::for_each(player.begin(), player.end(), [&](BlackjackPlayer &p) {
                participant.push_back(&p);
            });
            std::for_each(bot.begin(), bot.end(), [&](BlackjackBot &b) {
                participant.push_back(&b);
            });
            
            //std::shuffle(participant.begin(), participant.end(), 
            //    std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count()));
            
            break;
        }
        catch (std::logic_error &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Error on playgame - likely from stoi" << std::endl;
        }
        catch (exception &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Banyak partisipan maksimum: " << participantLimit << std::endl;
        }
    }
    
    std::for_each(player.begin(), player.end(), [](BlackjackPlayer &p) {
        p.askForName();
    });
    
    std::for_each(participant.begin(), participant.end(), [&](BlackjackParticipant *p) {
        p->getInitialCards(deck);
    });

    std::cout << std::endl << "Keadaan setelah pengambilan kartu awal" << std::endl;
    std::for_each(participant.begin(), participant.end(), [&](BlackjackParticipant *p) {
        p->printInfo();
        std::cout << std::endl;
    });
    pause();

    std::for_each(participant.begin(), participant.end(), [&](BlackjackParticipant *p) {
        p->playTurn(deck);
        pause();
    });

    sortPointer(participant);
    std::reverse(participant.begin(), participant.end());
    int idx = 0;
    std::cout << "Peringkat akhir:" << std::endl;
    std::for_each(participant.begin(), participant.end(), [&](BlackjackParticipant *p) {
        std::cout << ++idx << "." << std::endl;
        p->printInfo(0);
        printScore(*p);
        std::cout << std::endl;
    });
    std::cout << std::endl;

    
}
