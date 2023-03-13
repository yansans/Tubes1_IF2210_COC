#include "../Player/Player.hpp"
#include "../Exception/Exception.h"
#include "../InventoryHolder/DeckCards.hpp"
#include "../Command/CommandList.hpp"
#include "../Turn/Turn.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

class KerajaanPermen{
private:
    vector<Player*> players;
    DeckCards deckCards;
    // ! const long long winningScore = 1LL << 32;
    const long long winningScore = 10;
    long long rewardPoint = 64;
    const set<string> basicCommand = {"DOUBLE", "NEXT", "HALF"};
    const set<string> abilityCommand = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};

public:
    void inputPlayers(){
        for(int i=1;i<=7;i++){
            string nama;
            printf("Masukan nama player %d : ", i);
            getline(cin, nama);
            this->players.push_back(new Player(nama));
        }
    }

    bool checkFileExist(string fileName){
        ifstream tmp(fileName);
        return tmp.good();
    }

    string getFileName(){
        bool inputValid = false;
        string fileName;
        while(!inputValid){
            try{
                printf("Masukan nama file : ");
                getline(cin, fileName);
                bool exist = checkFileExist(fileName);
                if(!exist)throw InvalidFileNameException();
                inputValid = true;
            }catch(InvalidFileNameException e){
                printf("File tidak ditemukan, tolong masukan kembali nama file\n");
            }
        }
        return fileName;
    }

    DeckCards inputDeckCard(){
        printf("Pilih opsi membentuk urutan kartu:\n");
        printf("1. random\n");
        printf("2. baca dari file\n");
        printf("Masukan angka : ");
        string input;
        getline(cin, input);
        if(input == "1"){
            return DeckCards();
        }else if(input == "2"){
            string fileName = getFileName();
            return DeckCards(fileName);
        }else{
            throw InvalidOptionInputException();
        }
    }

    void inputDeckCardLoop(){
        bool inputValid = false;
        while(!inputValid){
            try{
                this->deckCards = inputDeckCard();
                inputValid = true;
            }catch(InvalidOptionInputException e){
                printf("Pilihan tidak valid, tolong pilih opsi yang diberikan\n");
            }catch(InvalidFileInputNamingFormatException e){
                printf("Format masukan file tidak sesuai format.\n");
            }
        }
    }

    long long highestScore(){
        return 1;
        // ! return (*max_element(players.begin(), players.end())).getPoint();
    }

    void displayEndGame(){
        printf("Permainan berakhir.\n");
        printf("Leaderboard:\n");
        // ! sort(players.begin(), players.end());
        for(int i=0;i<7;i++){
            printf("%d. %s: %lld\n", i+1, players[i]->getName().c_str(), players[i]->getPoint());
        }
        printf("Permainan dimenangkan oleh %s.\n", players[0]->getName().c_str());
    }

    string playerOptionInput(Player& player){
        printf("Masukan perintah yang ingin dilakukan: ");
        string input;
        getline(cin, input);
        string upperinput;
        transform(input.begin(), input.end(), std::back_inserter(upperinput), 
            [](char c) {
                return c - (('a' <= c && c <= 'z') ? 32 : 0);
            }
        );

        try{CommandList::execute(input, rewardPoint, player.getName());}
        catch(InvalidCommand e){
            try{
                // ! execute ability
            }catch(InvalidCommand e){ // ! exception ability
                throw InvalidOptionInputException();
            }
        }
    }

    void playerMenu(Player& player){
        printf("Giliran %s: \n", player.getName().c_str());
        // ! print punya ability apa
        bool finish = false;
        while(!finish){
            try{
                string input = playerOptionInput(player);
                finish = true;
            }catch(InvalidOptionInputException e){
                printf("Masukan tidak valid, tolong masukan keyword yang sesuai.\n");
            }
        }
        cout << endl;
        // ! next
    }

    void playGame(){
        inputPlayers();
        inputDeckCardLoop();
        Turn round(players);
        // ! while(highestScore() < winningScore){
        for(int i=0;i<10;i++){
            Player* currentPlayer = round.currentTurn();
            playerMenu(*currentPlayer);
            round.nextTurn();
            // ! ganti round, last round, cek combo
        }

        displayEndGame();
    }

};

