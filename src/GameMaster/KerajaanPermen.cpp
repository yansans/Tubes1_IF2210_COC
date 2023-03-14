#include "../Player/Player.hpp"
#include "../Exception/Exception.h"
#include "../InventoryHolder/DeckCards.hpp"
#include "../InventoryHolder/TableCards.hpp"
#include "../Command/CommandList.hpp"
#include "../AbilityHolder/AbilityHolder.hpp"
#include "../Turn/Turn.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include <random>
using namespace std;

class KerajaanPermen{
private:
    vector<Player*> players;
    TableCards tableCards;
    DeckCards deckCards;
    // ! const long long winningScore = 1LL << 32;
    const long long winningScore = 100;
    long long rewardPoint = 64;
    AbilityHolder abilityHolder;
    Turn turn;
    // ? gak dipake const set<string> basicCommand = {"DOUBLE", "NEXT", "HALF"};
    // ? gak dipake const set<string> abilityCommand = {"RE-ROLL", "QUADRUPLE", "QUARTER", "REVERSE", "SWAP", "SWITCH", "ABILITYLESS"};

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
        return (*max_element(players.begin(), players.end(), playerptrcmp))->getPoint();
    }

    void displayEndGame(){
        printf("Permainan berakhir.\n");
        printf("Leaderboard:\n");
        sort(players.begin(), players.end(), playerptrcmp);
        reverse(players.begin(), players.end());
        for(int i=0;i<players.size();i++){
            printf("%d. %s: %lld\n", i+1, players[i]->getName().c_str(), players[i]->getPoint());
        }
        printf("Permainan dimenangkan oleh %s.\n", players[0]->getName().c_str());
    }

    void playerOptionInput(Player& player){
        printf("Masukan perintah yang ingin dilakukan: ");
        string input;
        getline(cin, input);
        string upperinput;
        transform(input.begin(), input.end(), back_inserter(upperinput), 
            [](char c) {
                return c - (('a' <= c && c <= 'z') ? 32 : 0);
            }
        );
        input = upperinput;

        try{CommandList::execute(input, rewardPoint, player.getName());}
        catch(InvalidCommand e){
            try{
                if(input == "GETPOINT")player.addPoint(rewardPoint); // ! sementara buat nge cheat
                else abilityHolder.executeAbility(input, &player, rewardPoint, players, deckCards, turn);
            }catch(InvalidCommand e){
                throw InvalidOptionInputException();
            }
        }
    }

    static bool playerptrcmp(Player* p1, Player* p2){
        return *p1 < *p2;
    }

    vector<Ability*> generateRandomAbility(){
        vector<Ability*> abilities = {
            new Abilityless(),
            new Quadruple(),
            new Quarter(),
            new ReRoll(),
            new Reverse(),
            new Swap(),
            new Switch()
        };
        shuffle(abilities.begin(), abilities.end(), mt19937_64(chrono::steady_clock::now().time_since_epoch().count()));
        return abilities;
    }

    void playerMenu(Player& player){
        printf("Giliran %s: \n", player.getName().c_str());
        printf("Pointmu sekarang : %lld\n", player.getPoint());
        player.getCards().displayCard();
        tableCards.displayCard();
        if(abilityHolder.checkPlayerAbility(&player) == NULL ||
            abilityHolder.checkPlayerAbility(&player)->getIsUsed()){
            printf("Kamu sedang tidak memiliki kartu ability\n");
        }else{
            cout << "Kamu memiliki kartu ability : " << abilityHolder.checkPlayerAbility(&player)->getAbilityName() << endl;
        }
        bool finish = false;
        while(!finish){
            try{
                playerOptionInput(player);
                finish = true;
            }catch(InvalidOptionInputException e){
                printf("Masukan tidak valid, tolong masukan keyword yang sesuai.\n");
            }catch(StillCurrentTurn e){
                // emang kosong, jalan lagi
            }
        }
        cout << endl;
        // ! next
    }

    void drawCards(int round){
        if(round == 1){ // ronde awal
            tableCards.clear();
            for(int i=0;i<players.size();i++){
                players[i]->reset(deckCards);
            }
            
            inputDeckCardLoop();

            for(Player* player : players){
                player->takeCards(deckCards);
            }
        }else{
            tableCards.drawCard(deckCards);
            for(Player* player : players){ // ? naroh ke deck, ambil lagi
                player->reset(deckCards);
                player->takeCards(deckCards);
            }
        }
        
        if(round == 2){
            vector<Ability *> randomAbilities = generateRandomAbility();
            for(int i=0;i<players.size();i++){
                abilityHolder.addAbility(players[i], randomAbilities[i]);
            }
        }
    }

    void gameLoop(){
        turn = Turn(players);
        abilityHolder = AbilityHolder(players);
        int lastRound = 0;
        while(highestScore() < winningScore){
            if(turn.getRound() != lastRound){ // ? dah bener
                lastRound = turn.getRound();
                drawCards(lastRound);
            }
            printf("Ronde : %d\n", turn.getRound());
            Player* currentPlayer = turn.currentTurn();
            playerMenu(*currentPlayer);
            turn.nextTurn();
            // ? ganti round, last round dah kelar
            // ! cek combo
            // ! Player* winner = getwinner();
            // ! winner->addPoint(rewardPoint);
        }
    }

    void playGame(){
        inputPlayers();
        gameLoop();
        displayEndGame();
        // ! tanya mau ngulang
    }

};

