#include "KerajaanPermen.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include <random>
using namespace std;

KerajaanPermen::~KerajaanPermen(){
    for(int i=0;i<players.size();i++){
        delete players[i];
    }
}

void KerajaanPermen::inputPlayers(){
    for(int i=1;i<=7;i++){
        string nama;
        printf("Masukan nama player %d : ", i);
        getline(cin, nama);
        this->players.push_back(new Player(nama));
    }
}

bool KerajaanPermen::checkFileExist(string fileName){
    ifstream tmp(fileName);
    return tmp.good();
}

string KerajaanPermen::getFileName(){
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

DeckCards KerajaanPermen::inputDeckCard(){
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

void KerajaanPermen::inputDeckCardLoop(){
    bool inputValid = false;
    while(!inputValid){
        try{
            Deck = inputDeckCard();
            inputValid = true;
        }catch(InvalidOptionInputException e){
            printf("Pilihan tidak valid, tolong pilih opsi yang diberikan\n");
        }catch(InvalidFileInputNamingFormatException e){
            printf("Format masukan file tidak sesuai format.\n");
        }
    }
}

long long KerajaanPermen::highestScore(){
    return (maxPointer(players))->getPoint();
}

void KerajaanPermen::displayEndGame(){
    printf("Permainan berakhir.\n");
    printf("Leaderboard:\n");
    sortPointer(players);
    reverse(players.begin(), players.end());
    for(int i=0;i<players.size();i++){
        printf("%d. %s: %lld\n", i+1, players[i]->getName().c_str(), players[i]->getPoint());
    }
    printf("Permainan dimenangkan oleh %s.\n", players[0]->getName().c_str());
}

void KerajaanPermen::playerOptionInput(Player& player){
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
            abilityHolder.executeAbility(input, &player, rewardPoint, players, Deck, turn);
        }catch(InvalidCommand e){
            throw InvalidOptionInputException();
        }
    }
}

vector<Ability*> KerajaanPermen::generateRandomAbility(){
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

void KerajaanPermen::playerMenu(Player& player){
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
}

void KerajaanPermen::drawCards(int round){
    if(round == 1){ // ronde awal
        // hapus semua
        tableCards.clear();
        for(Player* player : players){
            player->reset();
            abilityHolder.removeAbility(player);
        }
        
        inputDeckCardLoop();

        for(Player* player : players){
            player->takeCards();
        }
    }else{
        tableCards.drawCard();
    }
    
    if(round == 2){
        vector<Ability *> randomAbilities = generateRandomAbility();
        for(int i=0;i<players.size();i++){
            abilityHolder.addAbility(players[i], randomAbilities[i]);
        }
    }
}

void KerajaanPermen::checkWinner(){
    Player* winner = PlayerCombo::get_winner(players, tableCards);
    winner->addPoint(rewardPoint);

    cout << "Kartu meja: ";
    for(int i=0;i<tableCards.getSize()-1;i++){
        cout << tableCards.getItem(i) << " && ";
    }
    if(tableCards.getSize() != 0)cout << tableCards.getItem(tableCards.getSize() - 1);
    cout << endl;
    for(Player* player : players){
        cout << "Kartu " << player->getName() << ": "
                << player->getCards().getLeftCard() << " && " << player->getCards().getRightCard()
                << endl;
    }
    printf("%s menang, dan mendapat poin sebanyak : %lld\n\n", winner->getName().c_str(), rewardPoint);
}

void KerajaanPermen::gameLoop(){
    turn = Turn(players);
    abilityHolder = AbilityHolder(players);
    int lastRound = 0;
    while(highestScore() < winningScore){
        if(turn.getRound() != lastRound){
            if(lastRound == 6){ // cek kalo ganti round, dan bukan ronde awal banget (ronde 1 game 1)
                checkWinner();
            }
            if(highestScore() >= winningScore)break;
            lastRound = turn.getRound();
            drawCards(lastRound);
        }
        printf("Ronde : %d\n", turn.getRound());
        Player* currentPlayer = turn.currentTurn();
        playerMenu(*currentPlayer);
        turn.nextTurn();
    }
}

void KerajaanPermen::playGame(){
    inputPlayers();
    gameLoop();
    displayEndGame();
}


